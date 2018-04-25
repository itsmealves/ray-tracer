//
// Created by gabriel on 24/04/18.
//

#include "LightSource.h"

const Ray LightSource::lightRayTo(const arma::vec &point) const {
    arma::vec rayPoint = _position;
    arma::vec direction = _position - point;
    direction /= arma::norm(direction);

    return Ray(rayPoint, direction);
}
