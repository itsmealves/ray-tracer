//
// Created by gabriel on 28/05/18.
//

#include "ObjParser.h"
#include "../things/Triangle.h"


const void ObjParser::onElementDetection(Element *element) {
    insertElement(element);
}

Element *ObjParser::translate(const std::vector<std::string> &spellings) {
    int state = 0;

    for(unsigned long i = 0; i < spellings.size(); i++) {
        std::string spelling = spellings.at(i);

        switch(state) {
            case 0:
                if(spelling == "v") state = 1;
                else if(spelling == "f") state = 11;
                else if(spelling == "vn") state = 21;
                else if(spelling == "vt") state = 31;
                else state = -1;
                break;
            case 1:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    double x = std::stod(spellings.at(i + 0));
                    double y = std::stod(spellings.at(i + 1));
                    double z = std::stod(spellings.at(i + 2));

                    arma::vec v({x, y, z});
                    _vList.emplace_back(v);
                }

                break;
            case 11:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    std::string a = spellings.at(i + 0);
                    std::string b = spellings.at(i + 1);
                    std::string c = spellings.at(i + 2);

                    Thing *t = translateFace(a, b, c);
                    return Element::from(t);
                }

                break;
            case 21:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    double x = std::stod(spellings.at(i + 0));
                    double y = std::stod(spellings.at(i + 1));
                    double z = std::stod(spellings.at(i + 2));

                    arma::vec vn({x, y, z});
                    _vnList.push_back(vn);
                }

                break;
            case 31:
                if(spellings.size() < i + 3) {
                    state = -1;
                } else {
                    double x = std::stod(spellings.at(i + 0));
                    double y = std::stod(spellings.at(i + 1));
                    double z = std::stod(spellings.at(i + 2));

                    arma::vec vt({x, y, z});
                    _vtList.push_back(vt);
                }

                break;
            default:
                return nullptr;
        }
    }


    return nullptr;
}

Thing *ObjParser::translateFace(const std::string a, const std::string b, const std::string c) const {
    arma::vec p1 = processFaceToken(a);
    arma::vec p2 = processFaceToken(b);
    arma::vec p3 = processFaceToken(c);

    arma::vec v1 = _vList.at((unsigned long) p1.at(0) - 1);
    arma::vec v2 = _vList.at((unsigned long) p2.at(0) - 1);
    arma::vec v3 = _vList.at((unsigned long) p3.at(0) - 1);

    return new Triangle(_material, v1, v2, v3);
}

arma::vec ObjParser::processFaceToken(std::string token) const {
    std::string s;

    for(char c : token) {
        if(c == '/') break;
        s.push_back(c);
    }

    double v = std::stod(s);
    return arma::vec({v});
}



