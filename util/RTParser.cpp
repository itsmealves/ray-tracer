//
// Created by gabriel on 28/05/18.
//

#include "RTParser.h"
#include "ObjParser.h"
#include "../things/Plane.h"
#include "../things/Sphere.h"

const void RTParser::onElementDetection(Element *element) {
    if (element->isObjFile()) {
        ObjParser parser(element->material());

        if (parser.parse(element->path())) {
            for (Thing *thing : parser.things()) {

                addThing(thing);
            }
        }

    } else {
        insertElement(element);
    }
}

Element *RTParser::translate(const std::vector<std::string> &spellings) {
    int state = 0;

    for(unsigned long i = 0; i < spellings.size(); i++) {
        std::string spelling = spellings.at(i);

        switch(state) {
            case 0:
                if(spelling == "Sphere") state = 1;
                else if(spelling == "LightSource") state = 11;
                else if(spelling == "ObjFile") state = 21;
                else if(spelling == "AmbientColor") state = 31;
                else if(spelling == "Plane") state = 41;
                else if(spelling == "Point") state = 51;
                else if(spelling == "Material") state = 61;
                else if(spelling == "LightIntensity") state = 71;
                else if(spelling == "Color") state = 81;
                else state = -1;
                break;
            case 1:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    unsigned long c = std::stoul(spellings.at(i + 0));
                    double r = std::stod(spellings.at(i + 1));
                    unsigned long m = std::stoul(spellings.at(i + 2));

                    arma::vec center = pointList.at(c - 1);
                    Material material = materialList.at(m - 1);

                    auto *sphere = new Sphere(material, center, r);
                    return Element::from(sphere);
                }

                break;
            case 11:
                if(spellings.size() < i + 2) {
                    state = -1;
                } else {
                    unsigned long p = std::stoul(spellings.at(i + 0));
                    unsigned long l = std::stoul(spellings.at(i + 1));

                    arma::vec position = pointList.at(p - 1);
                    arma::vec intensity = lightIntensityList.at(l - 1);

                    LightSource lightSource(position, intensity);
                    return Element::from(lightSource);
                }

                break;
            case 21:
                if(spellings.size() < i + 2) {
                    state = -1;
                } else {
                    unsigned long m = std::stoul(spellings.at(i + 1));
                    Material material = materialList.at(m - 1);

                    return Element::from(spellings.at(i), material);
                }

                break;
            case 31:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    double r = std::stod(spellings.at(i + 0));
                    double g = std::stod(spellings.at(i + 1));
                    double b = std::stod(spellings.at(i + 2));

                    arma::vec color({r, g, b});
                    return Element::from(color);
                }

                break;
            case 41:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    unsigned long p = std::stoul(spellings.at(i + 0));
                    unsigned long v = std::stoul(spellings.at(i + 1));
                    unsigned long m = std::stoul(spellings.at(i + 2));

                    arma::vec point = pointList.at(p - 1);
                    arma::vec normal = pointList.at(v - 1);
                    Material material = materialList.at(m - 1);

                    auto *plane = new Plane(material, point, normal);
                    return Element::from(plane);
                }

                break;
            case 51:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    double x = std::stod(spellings.at(i + 0));
                    double y = std::stod(spellings.at(i + 1));
                    double z = std::stod(spellings.at(i + 2));

                    pointList.emplace_back(arma::vec({x, y, z}));
                }

                break;
            case 61:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    unsigned long d = std::stoul(spellings.at(i + 0));
                    unsigned long c = std::stoul(spellings.at(i + 1));
                    double s = std::stod(spellings.at(i + 2));

                    arma::vec diffuse = colorList.at(d - 1);
                    arma::vec specular = colorList.at(c - 1);

                    Material material(diffuse, specular, s);
                    materialList.emplace_back(material);
                }

                break;
            case 71:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    double r = std::stod(spellings.at(i + 0));
                    double g = std::stod(spellings.at(i + 1));
                    double b = std::stod(spellings.at(i + 2));

                    arma::vec intensity({r, g, b});
                    lightIntensityList.emplace_back(intensity);
                }

                break;
            case 81:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    double r = std::stod(spellings.at(i + 0));
                    double g = std::stod(spellings.at(i + 1));
                    double b = std::stod(spellings.at(i + 2));

                    arma::vec intensity({r, g, b});
                    colorList.emplace_back(intensity);
                }

                break;
            default:
                return nullptr;
        }
    }


    return nullptr;
}



