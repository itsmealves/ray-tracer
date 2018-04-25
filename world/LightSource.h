//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_LIGHTSOURCE_H
#define RAY_TRACER_LIGHTSOURCE_H

#include <armadillo>
#include "../engine/Ray.h"

class LightSource {
private:
    arma::vec _position;
    arma::vec _intensity;
public:
    LightSource(arma::vec position, arma::vec intensity);
    Ray lightRayTo(arma::vec point);
    arma::vec position();
    arma::vec intensity();
};


#endif //RAY_TRACER_LIGHTSOURCE_H
