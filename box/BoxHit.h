//
// Created by gabriel on 04/07/18.
//

#ifndef RAY_TRACER_BOXHIT_H
#define RAY_TRACER_BOXHIT_H

#include <armadillo>

class BoxHit {
private:
    bool _happened;
    arma::vec _nearest;
    arma::vec _farthest;
public:
    BoxHit() : _happened(false) {};
    BoxHit(arma::vec nearest, arma::vec farthest) :
            _happened(true), _nearest(nearest), _farthest(farthest) {};

    const arma::vec nearest() const {
        return _nearest;
    }

    const arma::vec farthest() const {
        return _farthest;
    }

    const bool happened() const {
        return _happened;
    }
};


#endif //RAY_TRACER_BOXHIT_H
