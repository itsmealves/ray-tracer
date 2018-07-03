//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_RAY_H
#define RAY_TRACER_RAY_H

#include <armadillo>

class Ray {
private:
    arma::vec _point;
    arma::vec _direction;
    arma::vec _inverseOfDirection;
public:
    Ray(const arma::vec &point, const arma::vec &direction) : _point(point), _direction(direction), _inverseOfDirection(1 / direction) {};

    const arma::vec &point() const {
        return _point;
    }

    const arma::vec &direction() const {
        return _direction;
    }

    const arma::vec &inverseOfDirection() const {
        return _inverseOfDirection;
    }
};


#endif //RAY_TRACER_RAY_H
