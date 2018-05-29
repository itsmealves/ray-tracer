//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_WORLD_H
#define RAY_TRACER_WORLD_H


#include <armadillo>
#include <vector>
#include "LightSource.h"
#include "Thing.h"
#include "../util/text.h"
#include "../util/RTParser.h"

class World {
private:
    arma::vec _ambientColor;
    std::vector<Thing *> _things;
    std::vector<LightSource> _lightSources;
public:
    World() : World(arma::vec({0, 0, 0})) {}

    explicit World(const arma::vec &ambientColor) : _ambientColor(ambientColor) {
        std::cout << "Mundo criado com cor ambiente " << colorToHex(ambientColor) << std::endl;
    };

    static World from(const std::string &descriptionFilename) {
        World world;
        world.fillFrom(descriptionFilename);
        return world;
    }

    const void fillFrom(const std::string &descriptionFilename) {
        RTParser parser;

        if(parser.parse(descriptionFilename)) {
            for(Thing *t : parser.things())
                addThing(t);

            for(const LightSource &l : parser.lightSources())
                addLightSource(l);

            _ambientColor = parser.ambientColor();
        }
    }

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
        std::cout << "Adicionando objeto do tipo " << thing->name() << " ao mundo:" << std::endl;
        std::cout << thing->getInfo() << std::endl;

        _things.push_back(thing);
    }

    void addLightSource(const LightSource &lightSource) {
        std::cout << "Adicionando fonte de luz ao mundo:" << std::endl;
        std::cout << lightSource.getInfo() << std::endl;

        _lightSources.push_back(lightSource);
    }
};


#endif //RAY_TRACER_WORLD_H
