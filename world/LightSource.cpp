//
// Created by gabriel on 24/04/18.
//

#include "LightSource.h"

const Ray LightSource::lightRayTo(const arma::vec &point, double *t) const {
    arma::vec direction = _position - point;
    *t = arma::norm(direction);
    return Ray(point, direction / *t);
}
