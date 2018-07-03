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
    std::string _name;
    Material _material;
public:
    Thing(const std::string &name, const Material &material) : _name(name), _material(material) {}
    virtual const arma::vec normalTo(const arma::vec &point) const = 0;
    virtual const Hit intersectedBy(const Ray &ray) const = 0;
    virtual const std::string getInfo() const = 0;
    virtual const arma::vec massCenter() const = 0;
    virtual const arma::vec maxBounds() const = 0;
    virtual const arma::vec minBounds() const = 0;

    const std::string &name() const {
        return _name;
    }

    const Material &material() const {
        return _material;
    };
};


#endif //RAY_TRACER_THING_H
