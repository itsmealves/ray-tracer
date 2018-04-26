//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_THING_H
#define RAY_TRACER_THING_H

#include <armadillo>
#include "../engine/Ray.h"
#include "../engine/Hit.h"

class Thing {
private:
    arma::vec _color;
public:
    Thing(const arma::vec &color) : _color(color) {}
    virtual arma::vec normalTo(const arma::vec &point) = 0;
    virtual Hit intersectedBy(const Ray &ray) = 0;

    const arma::vec &color() const {
        return _color;
    };
};


#endif //RAY_TRACER_THING_H
