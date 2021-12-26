//
// Created by orku on 26.12.2021.
//

#include "app.h"
#include <iostream>
#include <random>


int App::run() {
    std::cout << "Mission planner start" << std::endl;
    std::cout << "To start mission planning write path to directory in which you want to create file" << std::endl;
    std::cin >> path_to_file_;
    create_file(path_to_file_);

    int action;
    while (true) {
        std::cout << "\nSelect one of this actions:\n"
                     "\t0 - Create new mission\n"
                     "\t1 - Delete mission\n"
                     "\t2 - Show created missions\n"
                     "\t3 - Swap two missions\n"
                     "\t4 - Rewrite missions\n"
                     "\t5 - Stop" << std::endl;

        std::cin >> action;
        switch (action) {
            case NEW_MISSION:
                missions_.push_back(new_mission());
                break;
            case DELETE_MISSION:
                delete_mission();
                break;
            case SHOW_MISSIONS:
                show_missions();
                break;
            case SWAP_MISSIONS:
                swap_missions();
                break;
            case REWRITE_MISSION:
                rewrite_missions();
                break;
            case STOP:
                if (stop()) {
                    return 0;
                }
                break;
            default:
                std::cout << "Try again" << std::endl;
                break;
        }
    }
}

void App::create_file(const std::string &path) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 1000);
    int file_id = dist6(rng);
    path_to_file_ = path + "Mission_config_" + std::to_string(file_id) + ".txt";
    file_.open(path, std::ios::out);
    file_.close();
    std::cout << "New file was created : " << path_to_file_ << std::endl;
}


std::unique_ptr<Mission> App::new_mission() {
    std::cout << "Select new mission type: \n"
                 "\t0 - Dive\n"
                 "\t1 - Lift\n"
                 "\t2 - Move\n"
                 "\t3 - Return\n\n";
    int tmp;
    MissionType mission_type;
    while (true) {
        std::cin >> tmp;
        mission_type = static_cast<MissionType>(tmp);
        switch (mission_type) {
            case MissionType::DIVE:
                return create_dive_mission();
            case MissionType::LIFT:
                return create_lift_mission();
            case MissionType::MOVE:
                return create_move_mission();
            case MissionType::RETURN:
                return create_return_mission();
            default:
                std::cout << "Try again:\n\n";
        }
    }
}

void App::delete_mission() {
    std::cout << "You want delete last mission or specific mission?\n"
                 "\t0 - last mission\n"
                 "\t1 - specific mission\n" << std::endl;
    int tmp;
    while (true){
        std::cin >> tmp;
        if (tmp == 1 || tmp == 0){
            break;
        }
        std::cout << "Try again" << std::endl;
    }

    switch (tmp) {
        case 0:
            missions_.pop_back();
            break;
        case 1:
            std::cout << "Type mission id:" << std::endl;
            int id;
            while (true){
                std::cin >> id;
                if (id <= missions_.size()){
                    missions_.erase(missions_.begin() + id);
                    break;
                }
                std::cout << "Id out of range! Tru again!" << std::endl;
            }
        default:
            return;
    }
    std::cout << "Mission was deleted!" << std::endl;
}

void App::show_missions() {
    for (int i = 0; i < missions_.size(); ++i) {
        std::cout << "Mission id: " << i << "\n";
        std::cout << missions_[i]->mission() << std::endl;
    }
}

void App::swap_missions() {
    int id1;
    int id2;
    while (true){
        std::cout << "Type first mission id which you want to swap:" << std::endl;
        std::cin >> id1;
        std::cout << "Type second mission id which you want to swap:" << std::endl;
        std::cin >> id2;

        if ((id1 >= 0 && id1 <= missions_.size()) && (id2 >= 0 && id2 <= missions_.size())){
            std::swap(missions_[id1], missions_[id2]);
            break;
        }
        std::cout << "You type wrong ids! Try again!" << std::endl;
    }
}

void App::rewrite_missions() {
    int id;
    while (true){
        std::cout << "Type mission id which you want to rewrite" << std::endl;
        std::cin >> id;

        if (id >= 0 && id <= missions_.size()){
            missions_[id] = new_mission();
            break;
        }
        std::cout << "Yoy typed wrong mission id! Try again!" << std::endl;
    }
    std::cout << "Mission was rewritten!" << std::endl;
}


bool App::stop() {

    if (!missions_.back()->is_it_return_mission) {
        std::cout << "There is no return mission! You have to add it!" << std::endl;
        return false;
    }
    if (!file_.good()) {
        std::cerr << "Error: file is bad" << std::endl;
        return false;
    }
    file_.open(path_to_file_, std::ios::out);
    for (auto &mission: missions_) {
        file_ << mission->mission() << std::endl;
    }
    file_.close();
    return true;
}

std::unique_ptr<Mission> App::create_dive_mission() {
    std::unique_ptr<Mission> dive_mission;

    int tmp;
    Dive::SensorType dive_sensor_type;
    std::cout << "Select sensor type:\n"
                 "\t0 - monometr\n"
                 "\t1 - echo\n\n";
    while (true) {
        std::cin >> tmp;
        dive_sensor_type = static_cast<Dive::SensorType>(tmp);
        if (dive_sensor_type == Dive::SensorType::MONOMETR ||
            dive_sensor_type == Dive::SensorType::ECHO) {
            break;
        }
        std::cout << "Try again:\n\n";
    }


    Dive::MovingType dive_move_type;
    std::cout << "Select diving type\n"
                 "\t0 - Vertical\n"
                 "\t1 - Spiral\n\n";
    while (true) {
        std::cin >> tmp;
        dive_move_type = static_cast<Dive::MovingType>(tmp);
        if (dive_move_type == Dive::MovingType::WITH_VERTICAL_MOTORS ||
            dive_move_type == Dive::MovingType::SPIRAL) {
            break;
        }
        std::cout << "Try again\n\n";
    }
    int depth = 0;
    while (true) {
        std::cout << "Select set deep: " << std::endl;
        std::cin >> depth;
        dive_mission = std::make_unique<Dive>(depth, dive_sensor_type, dive_move_type);
        if (dive_mission->check()) {
            break;
        }
        std::cout << "You set wrong depth! Min depth is " << MIN_DEPTH << ", max is " << MAX_DEPTH << " !" << std::endl;
    }
    std::cout << "Diving mission was created!" << std::endl;
    return dive_mission;
}

std::unique_ptr<Mission> App::create_lift_mission() {
    std::unique_ptr<Mission> lift_mission;
    int tmp;
    Lift::SensorType dive_sensor_type;
    std::cout << "Select sensor type:\n"
                 "\t0 - monometr\n"
                 "\t1 - Echo\n\n";
    while (true) {
        std::cin >> tmp;
        dive_sensor_type = static_cast<Lift::SensorType>(tmp);
        if (dive_sensor_type == Lift::SensorType::MONOMETR ||
            dive_sensor_type == Lift::SensorType::ECHO) {
            break;
        }
        std::cout << "Try again:\n\n";
    }

    Lift::MovingType dive_move_type;
    std::cout << "Type surfacing type\n"
                 "\t0 - vertical\n"
                 "\t1 - spiral\n\n";
    while (true) {
        std::cin >> tmp;
        dive_move_type = static_cast<Lift::MovingType>(tmp);
        if (dive_move_type == Lift::MovingType::WITH_VERTICAL_MOTORS ||
            dive_move_type == Lift::MovingType::SPIRAL) {
            break;
        }
        std::cout << "Try again\n\n";
    }

    int depth = 0;
    while (true) {
        std::cout << "Type set deep " << std::endl;
        std::cin >> depth;
        lift_mission = std::make_unique<Lift>(depth, dive_sensor_type, dive_move_type);
        if (lift_mission->check()) {
            break;
        }
        std::cout << "You set wrong depth! Min depth is " << MIN_DEPTH << ", max is " << MAX_DEPTH << " !" << std::endl;
    }
    std::cout << "Lift mission was created!" << std::endl;
    return lift_mission;
}

std::unique_ptr<Mission> App::create_move_mission() {
    std::unique_ptr<Mission> move_mission;
    int tmp;
    std::cout << "Select moving type\n"
                 "\t0 - moving to point\n"
                 "\t1 - moving across linear trajectory\n\n" << std::endl;
    Move::MovingType moving_type;
    while (true) {
        std::cin >> tmp;
        moving_type = static_cast<Move::MovingType>(tmp);
        if (moving_type == Move::MovingType::POINT || moving_type == Move::MovingType::LINEAR) {
            break;
        }
        std::cout << "Try again" << std::endl;
    }

    std::cout << "Select deep control:\n"
                 "\t0 - based on monometr\n"
                 "\t1 -based on echo\n\n" << std::endl;
    Move::DeepControlType deep_control_type;
    while (true) {
        std::cin >> tmp;
        deep_control_type = static_cast<Move::DeepControlType>(tmp);
        if (deep_control_type == Move::DeepControlType::MONOMETR ||
            deep_control_type == Move::DeepControlType::ECHO) {
            break;
        }
        std::cout << "Try again:\n\n";
    }
    int x;
    int y;
    while (true) {
        std::cout << "Type X coordinate: " << std::endl;
        std::cin >> x;

        std::cout << "type Y coordinate: " << std::endl;
        std::cin >> y;

        move_mission = std::make_unique<Move>(x, y, moving_type, deep_control_type);
        if (move_mission->check()) {
            break;
        }
        std::cout << "Try again, wrong coordinates was set, x and y must be in range (" << MIN_X << ", " << MAX_X
                  << ")!" << std::endl;
    }
    std::cout << "Moving mission was created!" << std::endl;
    return move_mission;
}

std::unique_ptr<Mission> App::create_return_mission() {
    std::cout << "Return mission was created" << std::endl;
    return std::make_unique<Return>();
}