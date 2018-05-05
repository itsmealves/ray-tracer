//
// Created by gabriel on 24/04/18.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H

#include <armadillo>
#include "../world/Thing.h"

class Sphere : public Thing {
private:
    double _r;
    arma::vec _center;
public:
    Sphere(const Material &material, const arma::vec &center, double r) :
            Thing("Sphere", material), _r(r), _center(center) {};

    const arma::vec &center() const {
        return _center;
    };

    const double r() const {
        return _r;
    };

    const arma::vec normalTo(const arma::vec &point) const override {
        arma::vec normal = point - _center;
        return normal / arma::norm(normal);
    };

    const Hit intersectedBy(const Ray &ray) const override;

    const std::string getInfo() const override {
        std::stringstream stream;

        stream << "\t* Raio: " << r() << std::endl;
        stream << "\t* Centro: (" << center().at(0) << ", ";
        stream << center().at(1) << ", ";
        stream << center().at(2) << ")" << std::endl;
        stream << "\t* Material: " << std::endl;
        stream << material().getInfo() << std::endl;

        return stream.str();
    }
};


#endif //RAY_TRACER_SPHERE_H
