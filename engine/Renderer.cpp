//
// Created by gabriel on 24/04/18.
//

#include "Renderer.h"
#include "../tree/KDTree.h"

Renderer::Renderer(int windowWidth, int windowHeight, int imageWidth, int imageHeight, double f) {
    double fx = ((double) imageWidth) / ((double) windowWidth) * f;
    double fy = ((double) imageHeight) / ((double) windowHeight) * f;
    double cx = ((double) imageWidth) / 2.0;
    double cy = ((double) imageHeight) / 2.0;

    _kInv = arma::mat(3, 3, arma::fill::zeros);

    _kInv(2,2) = 1.0;
    _kInv(1,2) = cy / fy;
    _kInv(0,2) = -cx / fx;
    _kInv(0,0) = 1.0 / fx;
    _kInv(1,1) = -1.0 / fy;

    _width = imageWidth;
    _height = imageHeight;


    std::cout << "Configurações do motor de geração de imagem:" << std::endl;
    std::cout << "\t* Distância focal: " << f << std::endl;
    std::cout << "\t* Dimensões da janela de projeção: " << windowWidth << "x" << windowHeight << std::endl;
    std::cout << "\t* Dimensões da imagem final: " << imageWidth << "x" << imageHeight << std::endl << std::endl;
}

const Ray Renderer::shoot(const arma::vec &point) const {
    arma::vec direction = _kInv * point;
    arma::vec rayPoint = arma::vec({0, 0, 0});
    direction /= arma::norm(direction);

    return Ray(rayPoint, direction);
}

const void Renderer::render(const World &world, const std::string &filePath) const {
    std::cout << "Iniciando geração da imagem" << std::endl;

    std::ofstream file;
    file.open(filePath);
    file << "P3" << std::endl;
    file << _width << " " << _height << std::endl;
    file << "255" << std::endl;

    KDTree tree(world.things());
    std::cout << "Aguarde uns instantes" << std::endl;
    for(int j = 0; j < _height; j++) {
        for(int i = 0; i < _width; i++) {
            const int recursionLimit = 2;
            Ray ray = shoot(arma::vec({(double) i, (double) j, 1.0}));
            arma::vec color = trace(ray, tree, world, recursionLimit) + world.ambientColor();

            file << std::round(color.at(0) > 255.0? 255.0 : color.at(0)) << " ";
            file << std::round(color.at(1) > 255.0? 255.0 : color.at(1)) << " ";
            file << std::round(color.at(2) > 255.0? 255.0 : color.at(2)) << " ";
        }

        file << std::endl;
    }

    file.close();
    std::cout << "Imagem " << filePath << " pronta." << std::endl;
}


const Hit Renderer::getClosestHit(const Ray &ray, const KDTree &tree) const {
    Hit hit;
    std::vector<Thing *> things = tree.traverse(ray);

    for(Thing *t : things) {
        Hit currentHit = t->intersectedBy(ray);
        if(!currentHit.happened()) continue;
        if(currentHit.t() <= 0) continue;

        if(!hit.happened() || hit.t() > currentHit.t()) {
            hit = currentHit;
        }
    }

    return hit;
}

const arma::vec Renderer::trace(const Ray &ray, const KDTree &tree, const World &world, const int recursionLimit) const {
    arma::vec color({0, 0, 0});
    if(recursionLimit <= 0) return color;
    Hit hit = getClosestHit(ray, tree);

    if(hit.happened()) {
        arma::vec resultColor({0, 0, 0});

        for(const LightSource &lightSource : world.lightSources()) {
            double tLightSource = 0;
            Ray lightRay = lightSource.lightRayTo(hit.hitPoint(), &tLightSource);
            bool lightDisabled = checkForShadows(lightRay, world.things(), tLightSource);

            if(lightDisabled) continue;
            resultColor += illuminate(ray, lightRay, hit, lightSource);
        }

        color += reflect(resultColor, ray, hit, tree, world, recursionLimit);
    }

    return color;
}

const bool Renderer::checkForShadows(const Ray &lightRay, const std::vector<Thing *> things, const double tLightSource) const {
    for(Thing *t : things) {
        Hit shadowTest = t->intersectedBy(lightRay);
        if(shadowTest.happened() && shadowTest.t() > 0.001 && shadowTest.t() < tLightSource) {
            return true;
        }
    }

    return false;
}

const arma::vec Renderer::illuminate(const Ray &ray, const Ray &lightRay, const Hit &hit, const LightSource &lightSource) const {
    arma::vec color({0, 0, 0});
    const Material &material = hit.material();

    double lambertCosine = arma::dot(hit.normal(), lightRay.direction());
    double lambertComponent = lambertCosine > 0.0? lambertCosine : 0.0;
    color += (material.diffuseColor() % lightSource.intensity()) * lambertComponent;

    if(!material.isLambertian()) {
        arma::vec e = (ray.point() - hit.hitPoint());
        arma::vec eNorm = e / arma::norm(e);
        arma::vec h = eNorm + lightRay.direction();
        arma::vec hNorm = h / arma::norm(h);

        double phongCosine = arma::dot(hit.normal(), hNorm);
        double phongComponent = phongCosine > 0.0? std::pow(phongCosine, material.shineness()) : 0.0;
        color += (material.specularColor() % lightSource.intensity()) * phongComponent;
    }

    return color;
}

const arma::vec Renderer::reflect(const arma::vec &color, const Ray &ray, const Hit &hit, const KDTree &tree, const World &world, const int recursionLimit) const {
    double reflexivity = std::min(hit.material().reflexivity(), 1.0);

    if(reflexivity > 0.0) {
        arma::vec d = hit.hitPoint() - ray.point();
        arma::vec dNorm = d / arma::norm(d);
        arma::vec r = dNorm - 2 * hit.normal() * arma::dot(hit.normal(), dNorm);
        arma::vec rNorm = r / arma::norm(r);

        Ray reflectedRay = Ray(hit.hitPoint(), rNorm);
        return color * (1 - reflexivity) + reflexivity * (trace(reflectedRay, tree, world, recursionLimit - 1));
    }

    return color;
}
