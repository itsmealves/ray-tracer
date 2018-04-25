//
// Created by gabriel on 24/04/18.
//

#include "Ray.h"

Ray::Ray(const arma::vec &point, const arma::vec &direction) {
    _point = point;
    _direction = direction;
}

arma::vec Ray::point()const {
    return _point;
}

arma::vec Ray::direction()const {
    return _direction;
}
