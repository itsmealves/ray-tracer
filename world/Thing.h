//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_THING_H
#define RAY_TRACER_THING_H

#include <armadillo>
#include "../engine/Ray.h"
#include "../engine/Hit.h"
#include "Material.h"

class Thing {
private:
    Material _material;
public:
    Thing(const Material &material) : _material(material) {}
    virtual const arma::vec normalTo(const arma::vec &point) const = 0;
    virtual const Hit intersectedBy(const Ray &ray) const = 0;

    const Material &material() const {
        return _material;
    };
};


#endif //RAY_TRACER_THING_H
