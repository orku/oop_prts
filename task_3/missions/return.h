//
// Created by orku on 25.12.2021.
//

#ifndef TASK_3_RETURN_H
#define TASK_3_RETURN_H

#include "mission.h"
#include <sstream>

class Return : public Mission{
    Return();
    ~Return() override = default;
    std::string mission();
};


#endif //TASK_3_RETURN_H
