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

    Thing *translateFace(std::string a, std::string b, std::string c) const;

public:
    ObjParser() : Parser() {}
    const void onElementDetection(Element *element) override;
    Element *translate(const std::vector<std::string> &spellings) override;
};


#endif //RAY_TRACER_OBJPARSER_H
