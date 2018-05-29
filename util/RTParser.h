//
// Created by gabriel on 28/05/18.
//

#ifndef RAY_TRACER_RTPARSER_H
#define RAY_TRACER_RTPARSER_H

#include <armadillo>
#include <iostream>
#include "../world/LightSource.h"
#include "Element.h"
#include "Parser.h"

class RTParser : public Parser {
private:
    std::vector<arma::vec> pointList;
    std::vector<arma::vec> colorList;
    std::vector<Material> materialList;
    std::vector<arma::vec> lightIntensityList;
public:
    const void onElementDetection(Element *element);
    Element *translate(const std::vector<std::string> &spellings) override;
};


#endif //RAY_TRACER_RTPARSER_H
