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
        arma::vec _vn1;
        arma::vec _vn2;
        arma::vec _vn3;
        Plane _plane;
        bool _usePlaneNormal = true;
        const arma::vec calculateNormalTo(const arma::vec &col) const;
    public:
        Triangle(const Material &material, const arma::vec &v1, const arma::vec &v2, const arma::vec &v3) :
                Thing("Triangle", material), _v1(v1), _v2(v2), _v3(v3), _plane(Plane(material, v1, arma::cross(v2 - v1, v3 - v1))) {};
        Triangle(const Material &material, const arma::vec &v1, const arma::vec &v2, const arma::vec &v3, const arma::vec &vn1, const arma::vec &vn2, const arma::vec &vn3) :
                Thing("Triangle", material), _v1(v1), _v2(v2), _v3(v3), _plane(Plane(material, v1, arma::cross(v2 - v1, v3 - v1))),
                _usePlaneNormal(false), _vn1(vn1), _vn2(vn2), _vn3(vn3) {};

        const arma::vec &v1() const {
            return _v1;
        };

        const arma::vec &v2() const {
            return _v2;
        };

        const arma::vec &v3() const {
            return _v3;
        };

    const arma::vec massCenter() const override {
        return (_v1 + _v2 + _v3) / 3;
    }

    const arma::vec minBounds() const override {
        double x = std::min(v1().at(0), std::min(v2().at(0), v3().at(0)));
        double y = std::min(v1().at(1), std::min(v2().at(1), v3().at(1)));
        double z = std::min(v1().at(2), std::min(v2().at(2), v3().at(2)));

        return arma::vec({x, y, z});
    }

    const arma::vec maxBounds() const override {
        double x = std::max(v1().at(0), std::max(v2().at(0), v3().at(0)));
        double y = std::max(v1().at(1), std::max(v2().at(1), v3().at(1)));
        double z = std::max(v1().at(2), std::max(v2().at(2), v3().at(2)));

        return arma::vec({x, y, z});
    }

    const arma::vec normalTo(const arma::vec &point) const override {
            if(_usePlaneNormal) return _plane.normalTo(point);
            else return calculateNormalTo(point);
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
