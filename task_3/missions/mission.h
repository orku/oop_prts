
#ifndef TASK_3_MISSION_H
#define TASK_3_MISSION_H

#include <string>

static constexpr unsigned int MAX_DEPTH = 100;
static constexpr unsigned int MIN_DEPTH = 0;
static constexpr int MAX_X = 5000;
static constexpr int MIN_X = -5000;
static constexpr int MAX_Y = 5000;
static constexpr int MIN_Y = -5000;

enum MissionType {
    DIVE = 0, LIFT, MOVE, RETURN, UNDEFINED
};

class Mission {
public:
    virtual ~Mission() = default;

    virtual bool check() = 0;

    virtual std::string mission() = 0;
};


#endif //TASK_3_MISSION_H
