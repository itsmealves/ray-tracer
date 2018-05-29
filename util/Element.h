//
// Created by gabriel on 28/05/18.
//

#ifndef RAY_TRACER_ELEMENT_H
#define RAY_TRACER_ELEMENT_H

#include <armadillo>
#include "../world/Thing.h"
#include "../world/LightSource.h"

class Element {
private:
    arma::vec _ambientColor;
    Thing *_thing{};
    std::string _path;
    LightSource _lightSource = LightSource();
    Material _material;
    bool _isThing = false;
    bool _isLightSource = false;
    bool _isObjFile = false;
    bool _isAmbientColor = false;
public:
    explicit Element(Thing *thing) : _thing(thing), _isThing(true) {}
    Element(const arma::vec color) : _ambientColor(color), _isAmbientColor(true) {}
    Element(const LightSource lightSource) : _lightSource(lightSource), _isLightSource(true) {}
    Element(const std::string path, const Material material) : _path(path), _material(material), _isObjFile(true) {}

    static Element *from(Thing *thing) {
        return new Element(thing);
    }

    static Element *from(const arma::vec color) {
        return new Element(color);
    }

    static Element *from(const std::string path, const Material material) {
        return new Element(path, material);
    }

    static Element *from(const LightSource lightSource) {
        return new Element(lightSource);
    }

    const bool isThing() const {
        return _isThing;
    }

    const bool isObjFile() const {
        return _isObjFile;
    }

    const bool isLightSource() const {
        return _isLightSource;
    }

    const bool isAmbientColor() const {
        return _isAmbientColor;
    }

    Thing *thing() const {
        return _thing;
    }

    Material material() const {
        return _material;
    }

    std::string path() const {
        return _path;
    }

    const LightSource lightSource() const {
        return _lightSource;
    }

    const arma::vec ambientColor() const {
        return _ambientColor;
    }
};


#endif //RAY_TRACER_ELEMENT_H
