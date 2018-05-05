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
        double tn = (arma::dot(u, v) * arma::dot(w, u)) - (arma::dot(u, u) * arma::dot(w, v));

        double s = sn / d;
        double t = tn / d;

        if(s >= 0 && t >= 0 && s + t <= 1) {
            //planeHit.hitPoint().print();
            return planeHit;
        }
    }

    return Hit();
}
