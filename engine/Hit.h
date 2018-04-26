//
// Created by gabriel on 25/04/18.
//

#ifndef RAY_TRACER_HIT_H
#define RAY_TRACER_HIT_H

#include <armadillo>

class Hit {
private:
    arma::vec _color;
    arma::vec _normal;
    arma::vec _hitPoint;
    bool _happened;
public:
    Hit() : _happened(false) {};
    Hit(const arma::vec &color, const arma::vec &normal, const arma::vec &hitPoint) :
            _happened(true), _color(color), _normal(normal), _hitPoint(hitPoint) {};

    const arma::vec &color() const {
        return _color;
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
