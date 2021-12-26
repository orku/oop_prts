//
// Created by orku on 26.12.2021.
//

#ifndef TASK_3_APP_H
#define TASK_3_APP_H

#include <string>
#include <fstream>
#include <memory>
#include <vector>

#include "dive.h"
#include "lift.h"
#include "move.h"
#include "return.h"

enum Actions {
    NEW_MISSION = 0,
    DELETE_MISSION,
    SHOW_MISSIONS,
    SWAP_MISSIONS,
    REWRITE_MISSION,
    STOP
};

class App {
public:
    App() = default;
    ~App() = default;
    int run();

private:
    std::unique_ptr<Mission> new_mission();
    void delete_mission();
    void show_missions();
    void swap_missions();
    void rewrite_missions();
    bool stop();
    void create_file(const std::string& path);

    std::string path_to_file_;
    std::fstream file_;
    std::vector<std::unique_ptr<Mission>> missions_;

    std::unique_ptr<Mission> create_dive_mission();
    std::unique_ptr<Mission> create_lift_mission();
    std::unique_ptr<Mission> create_move_mission();
    std::unique_ptr<Mission> create_return_mission();

};


#endif //TASK_3_APP_H
