//
// Created by orku on 25.12.2021.
//

#ifndef TASK_3_LIFT_H
#define TASK_3_LIFT_H


#include "mission.h"

class Lift : public Mission {
public:
    Lift() = delete;

    ~Lift() override = default;

    explicit Lift(int set_deep, int sensor, int moving);

    std::string mission() override;

    bool check() override;

    enum SensorType {
        MONOMETR = 0, ECHO
    };
    enum MovingType {
        WITH_VERTICAL_MOTORS = 0, SPIRAL
    };

private:
    int sensor_;
    int moving_;
    int set_depth_;
};


#endif //TASK_3_LIFT_H
