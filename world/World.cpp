//
// Created by gabriel on 24/04/18.
//

#include "World.h"

World::World(arma::vec ambientColor) {
    _ambientColor = ambientColor;
}

arma::vec World::ambientColor() {
    return _ambientColor;
}

std::vector<Thing *> World::things() {
    return _things;
}

std::vector<LightSource> World::lightSources() {
    return _lightSources;
}

void World::addThing(Thing *thing) {
    _things.push_back(thing);
}

void World::addLightSource(LightSource lightSource) {
    _lightSources.push_back(lightSource);
}


