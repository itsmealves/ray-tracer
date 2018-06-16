//
// Created by gabriel on 02/05/18.
//

#ifndef RAY_TRACER_MATERIAL_H
#define RAY_TRACER_MATERIAL_H

#include <armadillo>
#include "../util/text.h"

class Material {
private:
    arma::vec _diffuseColor;
    arma::vec _specularColor;
    double _shineness;
    double _reflexivity;
    bool _isLambertian;
public:
    Material() = default;
    Material(const arma::vec &color, const double shineness, const double reflexivity) : Material(color, color, shineness, reflexivity) {}
    Material(const arma::vec &diffuseColor, const arma::vec &specularColor, const double shineness, const double reflexivity) :
            _diffuseColor(diffuseColor), _specularColor(specularColor),
            _shineness(shineness), _reflexivity(reflexivity), _isLambertian(shineness <= 0) {}

    const arma::vec &diffuseColor() const {
        return _diffuseColor;
    }

    const arma::vec &specularColor() const {
        return _specularColor;
    }

    const double shineness() const {
        return _shineness;
    }

    const double reflexivity() const {
        return _reflexivity;
    }

    const bool isLambertian() const {
        return _isLambertian;
    }

    const std::string getInfo() const {
        std::stringstream stream;

        stream << "\t\t* Cor difusa: " << colorToHex(diffuseColor()) << std::endl;
        stream << "\t\t* Cor especular: " << colorToHex(specularColor()) << std::endl;
        stream << "\t\t* Shineness: " << shineness() << std::endl;

        return stream.str();
    }
};


#endif //RAY_TRACER_MATERIAL_H
