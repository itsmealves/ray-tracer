//
// Created by gabriel on 24/04/18.
//

#include "Sphere.h"

const Hit Sphere::intersectedBy(const Ray &ray) const {
    double a = arma::dot(ray.direction(), ray.direction());
    double b = 2.0 * arma::dot(ray.direction(), ray.point() - center());
    double c = arma::dot(ray.point() - center(), ray.point() - center()) - (r() * r());

    double discriminant = (b * b) - 4.0 * a * c;
    if(discriminant < 0.0) return Hit();

    double t1 = (std::sqrt(discriminant) - b) / (2.0 * a);
    double t2 = (-std::sqrt(discriminant) - b) / (2.0 * a);
    double t = t1 < t2? t1 : t2;

    arma::vec intersection = ray.point() + (ray.direction() * t);
    return Hit(material(), normalTo(intersection), intersection);
}




