//
// Created by orku on 25.12.2021.
//
#include <sstream>
#include "lift.h"

Lift::Lift(int set_deep, int sensor, int moving) : set_depth_(set_deep), sensor_(sensor), moving_(moving) {}

std::string Lift::mission() {
    std::stringstream result;
    result << "Lift mission:\n";
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
            result << "\tSurfacing with usage vertical motors\n";
            break;
        case MovingType::SPIRAL :
            result << "\tSurfacing diving\n";
            break;
    }

    return result.str();
}

bool Lift::check() {
    return set_depth_ <= MAX_DEPTH && set_depth_ >= MIN_DEPTH;
}
#include "lift.h"
