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
    Sphere(const arma::vec &color, const arma::vec &center, double r);
    arma::vec center();
    double r();
    arma::vec normalTo(const arma::vec &point) override;
    Hit intersectedBy(const Ray &ray) override;
};


#endif //RAY_TRACER_SPHERE_H
