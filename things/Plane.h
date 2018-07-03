//
// Created by gabriel on 04/05/18.
//

#ifndef RAY_TRACER_PLANE_H
#define RAY_TRACER_PLANE_H

#include <armadillo>
#include "../world/Thing.h"

class Plane : public Thing {
private:
    arma::vec _point;
    arma::vec _normal;
public:
    Plane(const Material &material, const arma::vec &point, const arma::vec &normal) :
            Thing("Plane", material), _point(point), _normal(normal / arma::norm(normal)) {

        if(_normal.at(2) > 0) _normal = -_normal;
    }

    const arma::vec &point() const {
        return _point;
    };

    const arma::vec normalTo(const arma::vec &point) const override {
        return _normal;
    };

    const Hit intersectedBy(const Ray &ray) const override;

    const arma::vec massCenter() const override {
        return arma::vec({NAN, NAN, NAN});
    }

    const arma::vec minBounds() const override {
        return massCenter();
    }

    const arma::vec maxBounds() const override {
        return massCenter();
    }

    const std::string getInfo() const override {
        std::stringstream stream;

        stream << "\t* Ponto: (" << point().at(0) << ", ";
        stream << point().at(1) << ", ";
        stream << point().at(2) << ")" << std::endl;


        stream << "\t* Normal: (" << _normal.at(0) << ", ";
        stream << _normal.at(1) << ", ";
        stream << _normal.at(2) << ")" << std::endl;

        stream << "\t* Material: " << std::endl;
        stream << material().getInfo() << std::endl;

        return stream.str();
    }
};


#endif //RAY_TRACER_PLANE_H
