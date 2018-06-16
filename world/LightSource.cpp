//
// Created by gabriel on 24/04/18.
//

#include "LightSource.h"

const Ray LightSource::lightRayTo(const arma::vec &point) const {
    arma::vec direction = _position - point;
    return Ray(point, direction / arma::norm(direction));
}
