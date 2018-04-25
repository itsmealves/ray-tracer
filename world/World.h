//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_WORLD_H
#define RAY_TRACER_WORLD_H


#include <armadillo>
#include <vector>
#include "LightSource.h"
#include "Thing.h"

class World {
private:
    arma::vec _ambientColor;
    std::vector<Thing *> _things;
    std::vector<LightSource> _lightSources;
public:
    World(arma::vec ambientColor);
    arma::vec ambientColor();
    std::vector<Thing *> things();
    std::vector<LightSource> lightSources();
    void addThing(Thing *thing);
    void addLightSource(LightSource lightSource);
};


#endif //RAY_TRACER_WORLD_H
