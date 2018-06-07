//
// Created by gabriel on 04/05/18.
//

#include "Triangle.h"

const Hit Triangle::intersectedBy(const Ray &ray) const {
    Hit planeHit = _plane.intersectedBy(ray);

    if(planeHit.happened()) {
        arma::vec u = v2() - v1();
        arma::vec v = v3() - v1();
        arma::vec w = planeHit.hitPoint() - v1();

        double d = std::pow(arma::dot(u, v), 2) - (arma::dot(u, u) * arma::dot(v, v));

        double sn = (arma::dot(u, v) * arma::dot(w, v)) - (arma::dot(v, v) * arma::dot(w, u));
        double s = sn / d;

        if(s >= 0) {
            double tn = (arma::dot(u, v) * arma::dot(w, u)) - (arma::dot(u, u) * arma::dot(w, v));
            double t = tn / d;

            if(t >= 0 && s + t <= 1) {
                Material material = planeHit.material();
                arma::vec normal = normalTo(planeHit.normal());
                arma::vec hitPoint = planeHit.hitPoint();

                return Hit(material, normal, hitPoint);
            }
        }
    }

    return Hit();
}

double distance(arma::vec a, arma::vec b) {
    arma::vec terms = arma::pow(a - b, 2);
    double squaredDistance = arma::sum(terms);
    return std::sqrt(squaredDistance);
}

const arma::vec Triangle::calculateNormalTo(const arma::vec &point) const {
    double d1 = distance(point, _v1);
    double d2 = distance(point, _v2);
    double d3 = distance(point, _v3);

    arma::vec normal = (d1 * _vn1 + d2 * _vn2 + d3 * _vn3) / (d1 + d2 + d3);
    normal = normal / arma::norm(normal);

    return normal;
}
