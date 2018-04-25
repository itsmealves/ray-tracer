//
// Created by gabriel on 24/04/18.
//

#include "LightSource.h"

LightSource::LightSource(arma::vec position, arma::vec intensity) {
    _position = position;
    _intensity = intensity;
}

arma::vec LightSource::position() {
    return _position;
}

arma::vec LightSource::intensity() {
    return _intensity;
}

Ray LightSource::lightRayTo(arma::vec point) {
    arma::vec rayPoint = _position;
    arma::vec direction = _position - point;
    direction /= arma::norm(direction);

    return Ray(rayPoint, direction);
}
