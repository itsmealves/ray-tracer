//
// Created by gabriel on 04/05/18.
//

#include "Plane.h"

const Hit Plane::intersectedBy(const Ray &ray) const {
    double numerator = arma::dot(_normal, _point - ray.point());
    double denominator = arma::dot(_normal, ray.direction());

    if(denominator != 0) {
        double r = numerator / denominator;
        if(r >= 0) return Hit(material(), _normal, ray.point() + ray.direction() * r, r);
    }

    return Hit();
}
