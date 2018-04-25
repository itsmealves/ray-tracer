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
    World(const arma::vec &ambientColor) : _ambientColor(ambientColor) {};

    const arma::vec &ambientColor() const {
        return _ambientColor;
    }

    const std::vector<Thing *> &things() const {
        return _things;
    }

    const std::vector<LightSource> &lightSources() const {
        return _lightSources;
    }

    void addThing(Thing *thing) {
        _things.push_back(thing);
    }

    void addLightSource(const LightSource &lightSource) {
        _lightSources.push_back(lightSource);
    }
};


#endif //RAY_TRACER_WORLD_H
