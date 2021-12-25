//
// Created by orku on 25.12.2021.
//

#ifndef TASK_3_MOVE_H
#define TASK_3_MOVE_H

#include "mission.h"

class Move : public Mission {
public:
    Move() = delete;

    ~Move() override = default;

    explicit Move(int x, int y, int moving, int deep_control, int accuracy = 20);

    std::string mission() override;

    bool check() override;

    enum MovingType{
        POINT = 0,
        LINEAR
    };

    enum DeepControlType{
        MONOMETR = 0,
        ECHO
    };

private:
    int x_;
    int y_;
    int sensor_;
    int moving_;
    int accuracy_;
};


#endif //TASK_3_MOVE_H
