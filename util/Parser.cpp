//
// Created by gabriel on 28/05/18.
//

#include "Parser.h"

Material Parser::parseMaterial(std::vector<std::string> spellings, unsigned long start) const {
    double rd = std::stod(spellings.at(start + 0));
    double gd = std::stod(spellings.at(start + 1));
    double bd = std::stod(spellings.at(start + 2));

    double rs = std::stod(spellings.at(start + 3));
    double gs = std::stod(spellings.at(start + 4));
    double bs = std::stod(spellings.at(start + 5));

    double shineness = std::stod(spellings.at(start + 6));

    arma::vec diffuse({rd, gd, bd});
    arma::vec specular({rs, gs, bs});

    return Material(diffuse, specular, shineness);
}

const bool Parser::parse(const std::string &filename) {
    std::string line;
    std::ifstream stream(filename);

    if(!stream.good()) return false;

    while(std::getline(stream, line)) {
        std::vector<std::string> spellings = getSpellingsFrom(line);
        Element *element = spellings.empty() ? nullptr : translate(spellings);

        if(element != nullptr) {
            onElementDetection(element);
        }

        delete element;
    }

    return true;
}
