//
// Created by orku on 14.11.2021.
//
#include <iostream>
#include <memory>
#ifndef TASK_1_PARSER_H
#define TASK_1_PARSER_H

struct PNITraxData {
    float kHeading;
    float kPitch;
    float kRoll;
    char kHeadingStatus;
    float kQuaternion[4];
    float kTemperature;
    bool kDistortion;
    bool kCalStatus;
    float kAccelX;
    float kAccelY;
    float kAccelZ;
    float kMagX;
    float kMagY;
    float kMagZ;
    float kGyroX;
    float kGyroY;
    float kGyroZ;
};

enum PNITraxDataID {
    kHeading = 5,
    kPitch = 24,
    kRoll = 25,
    kHeadingStatus = 79,
    kQuaternion = 77,
    kTemperature = 7,
    kDistortion = 8,
    kCalStatus = 9,
    kAccelX = 21,
    kAccelY = 22,
    kAccelZ = 23,
    kMagX = 27,
    kMagY = 28,
    kMagZ = 29,
    kGyroX = 74,
    kGyroY = 75,
    kGyroZ = 76
};

std::ostream& operator<<(std::ostream& out_stream, PNITraxData& data);

float cast_734_32(const char* byte_str, size_t start_pos, size_t size_of_obj);
void get_PNITraxData_from_msg(const char* byte_str, size_t msg_len, PNITraxData& data);

#endif //TASK_1_PARSER_H
