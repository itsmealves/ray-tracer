//
// Created by gabriel on 24/04/18.
//

#include "Sphere.h"

const Hit Sphere::intersectedBy(const Ray &ray) const {
    arma::vec centerToOrigin = ray.point() - _center;

    double x1 = 2.0 * arma::dot(centerToOrigin, ray.direction());
    double x2 = arma::dot(ray.direction(), ray.direction());
    double x3 = arma::dot(centerToOrigin, centerToOrigin) - (_r * _r);

    double discriminant = std::pow(x1, 2) - 4 * x2 * x3;
    if(discriminant < 0) return Hit();

    double t1 = (std::sqrt(discriminant) - x1) / (2.0 * x2);
    double t2 = (-std::sqrt(discriminant) - x1) / (2.0f * x2);
    double t = t1 < t2? t1 : t2;

    arma::vec intersection = ray.point() + ray.direction() * t;
    return Hit(material(), normalTo(intersection), intersection);
}




