//
// Created by orku on 14.11.2021.
//

#include "parser.h"
std::ostream& operator<<(std::ostream& out_stream, PNITraxData& data) {
    out_stream << "kHeading:   " << data.kHeading << '\n';
    out_stream << "kPitch:   " << data.kPitch << '\n';
    out_stream << "kRoll:   " << data.kRoll << '\n';
    out_stream << "kHeadingStatus:   " << data.kHeadingStatus << '\n';
    out_stream << "kQuaternion:   ";
    for (auto i: data.kQuaternion) {
        out_stream << i << " | ";
    }
    out_stream << '\n';
    out_stream << "kTemperature:   " << data.kTemperature << '\n';
    out_stream << "kDistortion:   " << data.kDistortion << '\n';
    out_stream << "kCalStatus:   " << data.kCalStatus << '\n';
    out_stream << "kAccelX:   " << data.kAccelX << '\n';
    out_stream << "kAccelY:   " << data.kAccelY << '\n';
    out_stream << "kAccelZ:   " << data.kAccelZ << '\n';
    out_stream << "kMagX:   " << data.kMagX << '\n';
    out_stream << "kMagY:   " << data.kMagY << '\n';
    out_stream << "kMagZ:   " << data.kMagZ << '\n';
    out_stream << "kGyroX:   " << data.kGyroX << '\n';
    out_stream << "kGyroY:   " << data.kGyroY << '\n';
    out_stream << "kGyroZ:   " << data.kGyroZ << '\n';
    return out_stream;
}

float cast_734_32(const char* byte_str, size_t start_pos, size_t size_of_obj){
    float fl;
    auto* ret_float = reinterpret_cast<char*>(&fl);

    for (size_t i = 0; i < size_of_obj; ++i) {
        ret_float[i] = byte_str[start_pos + size_of_obj -1 -i];
    }
    return fl;
}
