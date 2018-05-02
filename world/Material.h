//
// Created by gabriel on 02/05/18.
//

#ifndef RAY_TRACER_MATERIAL_H
#define RAY_TRACER_MATERIAL_H

#include <armadillo>

class Material {
private:
    arma::vec _diffuseColor;
    arma::vec _specularColor;
    double _shineness;
public:
    Material() {};
    Material(const arma::vec &diffuseColor, const arma::vec &specularColor, const double shineness) :
            _diffuseColor(diffuseColor), _specularColor(specularColor), _shineness(shineness) {};

    const arma::vec &diffuseColor() const {
        return _diffuseColor;
    }

    const arma::vec &specularColor() const {
        return _specularColor;
    }

    const double &shineness() const {
        return _shineness;
    }
};


#endif //RAY_TRACER_MATERIAL_H
