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
}

const Ray Renderer::shoot(const arma::vec &point) const {
    arma::vec direction = _kInv * point;
    arma::vec rayPoint = arma::vec({0, 0, 0});
    direction /= arma::norm(direction);

    return Ray(rayPoint, direction);
}

const void Renderer::render(const World &world, const std::string &filePath) const {
    Thing *t = world.things()[0];

    std::ofstream file;
    file.open(filePath);

    file << "P3" << std::endl;
    file << _width << " " << _height << std::endl;
    file << "255" << std::endl;


    for(int j = 0; j < _height; j++) {
        for(int i = 0; i < _width; i++) {
            arma::vec intersection;
            arma::vec color = world.ambientColor();
            arma::vec currentPoint = arma::vec({(double) i, (double) j, 1});

            Ray ray = shoot(currentPoint);

            if(t->intersectedBy(ray, intersection)) {
                arma::vec resultColor = arma::vec({0, 0, 0});

                for(unsigned long k = 0; k < world.lightSources().size(); k++) {
                    LightSource l = world.lightSources().at(k);
                    Ray lightRay = l.lightRayTo(intersection);
                    arma::vec normal = t->normalTo(intersection);

                    double cosine = arma::dot(normal, lightRay.direction());
                    double component = cosine > 0.0? cosine : 0.0;

                    resultColor += (t->color() % l.intensity()) * component;
                }

                resultColor(0) = resultColor(0) > 255.0? 255.0 : resultColor(0);
                resultColor(1) = resultColor(1) > 255.0? 255.0 : resultColor(1);
                resultColor(2) = resultColor(2) > 255.0? 255.0 : resultColor(2);

                color += resultColor;
            }

            file << std::round(color(0)) << " " << std::round(color(1)) << " " << std::round(color(2)) << " ";
        }

        file << std::endl;
    }


    file.close();
}


