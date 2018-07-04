//
// Created by calazans on 23/06/18.
//

#ifndef KDTREE_MISSINGMETHODS_H
#define KDTREE_MISSINGMETHODS_H

#include <armadillo>
#include "../world/Thing.h"

arma::vec getMinBounds(const Thing *value) {
    return value->minBounds();
};
arma::vec getCenter(const Thing *value) {
    return value->massCenter();
}
arma::vec getMaxBounds(const Thing *value) {
    return value->maxBounds();
}

#endif //KDTREE_MISSINGMETHODS_H
