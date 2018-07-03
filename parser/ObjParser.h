//
// Created by gabriel on 28/05/18.
//

#ifndef RAY_TRACER_OBJPARSER_H
#define RAY_TRACER_OBJPARSER_H


#include "Parser.h"
#include <armadillo>

class ObjParser : public Parser {
private:
    std::vector<arma::vec> _vList;
    std::vector<arma::vec> _vtList;
    std::vector<arma::vec> _vnList;
    Material _material;

    arma::vec processFaceToken(std::string token) const;
    Thing *translateFace(std::string a, std::string b, std::string c) const;

public:
    ObjParser(const Material material) : Parser(), _material(material) {}
    const void onElementDetection(Element *element) override;
    Element *translate(const std::vector<std::string> &spellings) override;
};


#endif //RAY_TRACER_OBJPARSER_H
