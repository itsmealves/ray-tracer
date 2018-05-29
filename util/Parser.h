//
// Created by gabriel on 28/05/18.
//

#ifndef RAY_TRACER_PARSER_H
#define RAY_TRACER_PARSER_H

#include <armadillo>
#include "../world/Material.h"
#include "../world/Thing.h"
#include "../world/LightSource.h"
#include "Element.h"

class Parser {
private:
    arma::vec _ambientColor;
    std::vector<Thing *> _things;
    std::vector<LightSource> _lightSources;

    const bool isBlank(char c) const {
        return c == ' ' || c == '\n' || c == '\t' || c == '\r';
    }

    const bool isEndOfLine(char c) const {
        return c == '#';
    }

    const std::vector<std::string> getSpellingsFrom(std::string line) const {
        std::string currentSpelling;
        std::vector<std::string> spellings;

        for(char c : line) {
            if(isEndOfLine(c)) break;

            if(!isBlank(c)) {
                currentSpelling.push_back(c);
            } else if(!currentSpelling.empty()) {
                spellings.push_back(currentSpelling);
                currentSpelling = "";
            }
        }

        if(!currentSpelling.empty()) {
            spellings.push_back(currentSpelling);
        }

        return spellings;
    }

protected:
    const int _materialSize = 7;
    Material parseMaterial(std::vector<std::string> spellings, unsigned long start) const;

    void insertElement(Element *element) {
        if(element->isThing())
            _things.push_back(element->thing());
        else if(element->isLightSource())
            _lightSources.push_back(element->lightSource());
        else if(element->isAmbientColor())
            _ambientColor = element->ambientColor();
    }

    virtual const void onElementDetection(Element *element) = 0;
    virtual Element *translate(const std::vector<std::string> &spellings) = 0;

    void addThing(Thing *thing) {
        _things.push_back(thing);
    }

public:
    const std::vector<Thing *> things() const {
        return _things;
    }

    const std::vector<LightSource> lightSources() const {
        return _lightSources;
    }

    const arma::vec ambientColor() const {
        return _ambientColor;
    }

    const bool parse(const std::string &filename);
};



#endif //RAY_TRACER_PARSER_H
