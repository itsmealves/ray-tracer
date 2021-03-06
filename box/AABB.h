//
// Created by calazans on 23/06/18.
//

#ifndef KDTREE_AABB_H
#define KDTREE_AABB_H

#include <armadillo>
#include "../world/Thing.h"
#include "BoxHit.h"
enum DIRECTION{
    X_DIR =0,Y_DIR,
    Z_DIR

};

class AABB {
private:
    std::vector<Thing *> _things;
    arma::vec _minBounds;
    arma::vec _maxBounds;
    AABB();
public:
    AABB(const arma::vec minBounds, const arma::vec maxBounds) :
        _minBounds(minBounds), _maxBounds(maxBounds) {};

    AABB(const arma::vec minBounds, const arma::vec maxBounds, const std::vector<Thing *> things) :
        _minBounds(minBounds), _maxBounds(maxBounds), _things(things) {};

    const arma::vec maxBounds() const {
        return _maxBounds;
    }
    const arma::vec minBounds() const {
        return _minBounds;
    }

    const std::vector<Thing *> things() const {
        return _things;
    }

    BoxHit intersectedBy(const Ray &ray) const;

    AABB *join(AABB *otherBox) const;
    AABB **divideAABB(DIRECTION dir, double cutPoint) const;
};


#endif //KDTREE_AABB_H
