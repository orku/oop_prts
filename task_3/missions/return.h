//
// Created by orku on 25.12.2021.
//

#ifndef TASK_3_RETURN_H
#define TASK_3_RETURN_H

#include "mission.h"
#include <sstream>

class Return : public Mission {
public:
    Return();

    ~Return() override = default;

    std::string mission() override;

    bool check() override;
};


#endif //TASK_3_RETURN_H
