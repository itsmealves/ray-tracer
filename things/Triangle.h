//
// Created by gabriel on 04/05/18.
//

#ifndef RAY_TRACER_TRIANGLE_H
#define RAY_TRACER_TRIANGLE_H

#include <armadillo>
#include "../world/Material.h"
#include "../world/Thing.h"
#include "Plane.h"

class Triangle : public Thing {
    private:
        arma::vec _v1;
        arma::vec _v2;
        arma::vec _v3;
        Plane _plane;
    public:
        Triangle(const Material &material, const arma::vec &v1, const arma::vec &v2, const arma::vec &v3) :
                Thing("Triangle", material), _v1(v1), _v2(v2), _v3(v3), _plane(Plane(material, v1, arma::cross(v2 - v1, v3 - v1))) {};

        const arma::vec &v1() const {
            return _v1;
        };

        const arma::vec &v2() const {
            return _v2;
        };

        const arma::vec &v3() const {
            return _v3;
        };

        const arma::vec normalTo(const arma::vec &point) const override {
            return _plane.normalTo(point);
        };

        const Hit intersectedBy(const Ray &ray) const override;


        const std::string getInfo() const override {
            std::stringstream stream;

            stream << "\t* V1: (" << v1().at(0) << ", ";
            stream << v1().at(1) << ", ";
            stream << v1().at(2) << ")" << std::endl;


            stream << "\t* V2: (" << v2().at(0) << ", ";
            stream << v2().at(1) << ", ";
            stream << v2().at(2) << ")" << std::endl;


            stream << "\t* V3: (" << v3().at(0) << ", ";
            stream << v3().at(1) << ", ";
            stream << v3().at(2) << ")" << std::endl;

            stream << "\t* Material: " << std::endl;
            stream << material().getInfo() << std::endl;

            return stream.str();
        }
};


#endif //RAY_TRACER_TRIANGLE_H
