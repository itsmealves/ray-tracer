//
// Created by gabriel on 24/04/18.
//

#include "Thing.h"

Thing::Thing(arma::vec color) {
    _color = color;
}

arma::vec Thing::color() {
    return _color;
}
