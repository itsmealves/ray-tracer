//
// Created by gabriel on 25/04/18.
//

#ifndef RAY_TRACER_HIT_H
#define RAY_TRACER_HIT_H

#include <armadillo>
#include "../world/Material.h"

class Hit {
private:
    bool _happened;
    arma::vec _normal;
    arma::vec _hitPoint;
    Material _material;
public:
    Hit() : _happened(false) {};
    Hit(const Material &material, const arma::vec &normal, const arma::vec &hitPoint) :
            _happened(true), _material(material), _normal(normal), _hitPoint(hitPoint) {};

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

    bool operator<(const Hit &hit) const {
        if(!_happened && hit.happened()) return false;
        else if(_happened && !hit.happened()) return true;
        else if(_happened && hit.happened()) return _hitPoint(2) < hit.hitPoint()(2);
        else return false;
    }

    bool operator>(const Hit &hit) const {
        return hit < *this;
    }
};


#endif //RAY_TRACER_HIT_H
