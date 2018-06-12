//
// Created by gabriel on 24/04/18.
//

#include "Renderer.h"

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

    for(int j = 0; j < _height; j++) {
        for(int i = 0; i < _width; i++) {
            const int recursionLimit = 3;
            Ray ray = shoot(arma::vec({(double) i, (double) j, 1}));
            arma::vec color = trace(ray, world, recursionLimit) + world.ambientColor();

            file << std::round(color.at(0) > 255.0? 255.0 : color.at(0)) << " ";
            file << std::round(color.at(1) > 255.0? 255.0 : color.at(1)) << " ";
            file << std::round(color.at(2) > 255.0? 255.0 : color.at(2)) << " ";
        }

        file << std::endl;
    }

    file.close();
    std::cout << "Imagem " << filePath << " pronta." << std::endl;
}

const arma::vec trace(const Ray &ray, const World &world, const int recursionLimit) const {
    Hit hit();
    arma::vec color({0, 0, 0});

    for(Thing *t : world.things()) {
        Hit currentHit = t->intersectedBy(ray);
        if((!hit.happened() && currentHit.happened()) || currentHit < hit)
            hit = currentHit;
    }

    if(hit.happened()) {
        arma::vec resultColor({0, 0, 0});

        for(LightSource lightSource : world.lightSources()) {
            resultColor += illuminate(hit, lightSource);
        }

        color += resultColor;
    }

    return color;
}

const arma::vec illuminate(const Hit &hit, const LightSource &lightSource) const {
    Material material = hit.material();
    Ray lightRay = l.lightRayTo(hit.hitPoint());

    double lambertCosine = arma::dot(hit.normal(), lightRay.direction());
    double lambertComponent = lambertCosine > 0.0? lambertCosine : 0.0;
    arma::vec lambert = (material.diffuseColor() % l.intensity()) * lambertComponent;

    if(!material.isLambertian()) {
        arma::vec h = /*ray.direction() + */lightRay.direction();
        arma::vec hNorm = h / arma::norm(h);

        double phongCosine = arma::dot(hit.normal(), hNorm);
        double phongComponent = phongCosine > 0.0? std::pow(phongCosine, material.shineness()) : 0.0;
        arma::vec phong = (material.specularColor() % l.intensity()) * phongComponent;

        return lambert + phong;
    }

    return lambert;
}
