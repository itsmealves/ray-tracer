//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_LIGHTSOURCE_H
#define RAY_TRACER_LIGHTSOURCE_H

#include <armadillo>
#include "../engine/Ray.h"

class LightSource {
private:
    arma::vec _position;
    arma::vec _intensity;
public:
    LightSource(const arma::vec &position, const arma::vec &intensity) : _position(position), _intensity(intensity) {};

    const Ray lightRayTo(const arma::vec &point) const;

    const arma::vec &position() const {
        return _position;
    };

    const arma::vec &intensity() const {
        return _intensity;
    };
};


#endif //RAY_TRACER_LIGHTSOURCE_H
