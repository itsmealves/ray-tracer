//
// Created by gabriel on 04/05/18.
//

#ifndef RAY_TRACER_TEXT_H
#define RAY_TRACER_TEXT_H

#include <armadillo>

static std::string toHex(int v) {
    std::stringstream stream;
    stream << std::hex << v;

    std::string color = stream.str();
    if(color.length() < 2) {
        return std::string(1, '0').append(color);
    }

    return color;
}

inline std::string colorToHex(const arma::vec &color) {
    return "#" + toHex((int) color.at(0)) + toHex((int) color.at(1)) + toHex((int) color.at(2));
}

#endif //RAY_TRACER_TEXT_H
