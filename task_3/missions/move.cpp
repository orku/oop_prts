//
// Created by orku on 25.12.2021.
//

#include "move.h"
#include <sstream>
Move::Move(int x, int y, int moving, int deep_control, int accuracy) : x_(x), y_(y), moving_(moving),
                                                                       sensor_(deep_control), accuracy_(accuracy) {}

bool Move::check() {
    return x_ <= MAX_X && x_ >= MIN_X && y_ <= MAX_Y && y_ >= MIN_Y;
}

std::string Move::mission() {
    std::stringstream result;
    result << "Moving mission:\n";
    switch (moving_){
        case MovingType::LINEAR :
            result << "\tMovement along the line\n";
            break;
        case MovingType::POINT :
            result << "\tMovement to the point\n";
            break;
    }
    result << "\tPoint coordinates: (" << x_ <<", " << y_  << "), accuracy: " << accuracy_ << "\n";
    switch (sensor_) {
        case DeepControlType::ECHO :
            result << "\tDeep control based on the echo\n";
            break;
        case DeepControlType::MONOMETR :
            result << "\tDeep control based on the monometr";
            break;
    }
    return result.str();
}
