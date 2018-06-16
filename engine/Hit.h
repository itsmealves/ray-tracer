//
// Created by gabriel on 25/04/18.
//

#ifndef RAY_TRACER_HIT_H
#define RAY_TRACER_HIT_H

#include <armadillo>
#include "../world/Material.h"

class Hit {
private:
    double _t;
    bool _happened;
    arma::vec _normal;
    arma::vec _hitPoint;
    Material _material;
public:
    Hit() : _happened(false) {};
    Hit(const Material &material, const arma::vec &normal, const arma::vec &hitPoint, const double t) :
            _happened(true), _material(material), _normal(normal), _hitPoint(hitPoint), _t(t) {};

    const Material &material() const {
        return _material;
    }

    const arma::vec &normal() const {
        return _normal;
    }

    const arma::vec &hitPoint() const {
        return _hitPoint;
    }

    const bool happened() const {
        return _happened;
    }

    const double t() const {
        return _t;
    }
};


#endif //RAY_TRACER_HIT_H
