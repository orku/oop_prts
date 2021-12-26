//
// Created by orku on 25.12.2021.
//

#include <sstream>
#include "dive.h"

Dive::Dive(int set_deep, int sensor, int moving) : set_depth_(set_deep), sensor_(sensor), moving_(moving) {}

std::string Dive::mission() {
    std::stringstream result;
    result << "Dive mission\n";
    switch (sensor_) {
        case SensorType::ECHO :
            result << "\tSetting deep based on echo sounder\n"
                      "\tSet distance from bottom: " << MAX_DEPTH - set_depth_ << "\n";
            break;
        case SensorType::MONOMETR :
            result << "\tSetting deep based on monometr\n"
                      "\tSet deep: " << set_depth_ << "\n";
            break;
    }

    switch (moving_) {
        case MovingType::WITH_VERTICAL_MOTORS :
            result << "\tDiving with usage vertical motors\n";
            break;
        case MovingType::SPIRAL :
            result << "\tSpiral diving\n";
            break;
    }

    return result.str();
}

bool Dive::check() {
    return (set_depth_ < MAX_DEPTH) && (set_depth_ > MIN_DEPTH);
}
