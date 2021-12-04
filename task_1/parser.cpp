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
void get_PNITraxData_from_msg(const char* byte_str, size_t msg_len, PNITraxData& data)
{
  for (size_t i = 0; i < msg_len; i += 1) {
    switch (static_cast<int>(byte_str[i])) {
      case PNITraxDataID::kHeading : {
        data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kPitch: {
        data.kPitch = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kRoll: {
        data.kRoll = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kHeadingStatus: {
        data.kHeadingStatus = byte_str[i + 1];
        i += sizeof(char);
        break;
      }
      case PNITraxDataID::kQuaternion: {
        for (float &j: data.kQuaternion) {
          j = cast_734_32(byte_str, i + 1, sizeof(float));
          i += sizeof(float);
        }
        break;
      }
      case PNITraxDataID::kTemperature: {
        data.kTemperature = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kDistortion: {
        if (auto fl =  cast_734_32(byte_str, i + 1, sizeof(bool)); fl > 0.00001){
          data.kDistortion = true;
        } else {
          data.kDistortion = false;
        }
        i += sizeof(bool);
        break;
      }
      case PNITraxDataID::kCalStatus: {
        if (auto fl =  cast_734_32(byte_str, i + 1, sizeof(bool)); fl > 0.00001){
          data.kCalStatus = true;
        } else {
          data.kCalStatus = false;
        }
        i += sizeof(bool);
        break;
      }
      case PNITraxDataID::kAccelX: {
        data.kAccelX = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kAccelY: {
        data.kAccelY = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kAccelZ: {
        data.kAccelZ = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kMagX: {
        data.kMagX = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kMagY: {
        data.kMagY = cast_734_32(byte_str, i + 1, sizeof(float));
        i += 4;
        break;
      }
      case PNITraxDataID::kMagZ: {
        data.kMagZ = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kGyroX: {
        data.kGyroX = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kGyroY: {
        data.kGyroY = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      case PNITraxDataID::kGyroZ: {
        data.kGyroZ = cast_734_32(byte_str, i + 1, sizeof(float));
        i += sizeof(float);
        break;
      }
      default:
        break;
    }
  }
}