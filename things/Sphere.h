//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H

#include <armadillo>
#include "../world/Thing.h"

class Sphere : public Thing {
private:
    double _r;
    arma::vec _center;
public:
    Sphere(const Material &material, const arma::vec &center, double r) :
            Thing(material), _r(r), _center(center) {};

    const arma::vec &center() const {
        return _center;
    };

    const double r() const {
        return _r;
    };

    const arma::vec normalTo(const arma::vec &point) const override {
        arma::vec normal = point - _center;
        return normal / arma::norm(normal);
    };

    const Hit intersectedBy(const Ray &ray) const override;
};


#endif //RAY_TRACER_SPHERE_H
