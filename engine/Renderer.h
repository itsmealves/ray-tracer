//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_RENDERER_H
#define RAY_TRACER_RENDERER_H

#include <armadillo>
#include "../world/World.h"
#include "Ray.h"

class Renderer {    
private:
    int _width;
    int _height;
    arma::mat _kInv;
    const Ray shoot(const arma::vec &point) const;
public:
    Renderer(int windowWidth, int windowHeight, int imageWidth, int imageHeight, double f);
    const void render(const World &world, const std::string &filePath) const;
};


#endif //RAY_TRACER_RENDERER_H
