//
// Created by gabriel on 28/05/18.
//

#include "ObjParser.h"


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

Thing *ObjParser::translateFace(std::string a, std::string b, std::string c) const {
    return nullptr;
}



