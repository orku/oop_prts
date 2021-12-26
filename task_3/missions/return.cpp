//
// Created by orku on 25.12.2021.
//

#include "return.h"

std::string Return::mission() {
    std::stringstream result;
    result << "Return mission";
    return result.str();
}

bool Return::check() {
    return true;
}

Return::Return() {
    is_it_return_mission = true;
}
