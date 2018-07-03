//
// Created by gabriel on 28/05/18.
//

#include "Parser.h"

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
