#include <iostream>
#include "parser.h"
void get_PNITraxData_from_msg(const char* byte_str, size_t msg_len, PNITraxData& data){
    for (size_t i = 0; i < msg_len; ++i) {
        switch (static_cast<int>(byte_str[i])) {
            case 5: {
                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
                i += sizeof(float);
            }
            case PNITraxDataID::kPitch: {
                data.kPitch = cast_734_32(byte_str, i + 1, sizeof(float));
                i += sizeof(float);
            }
            case PNITraxDataID::kRoll: {
                data.kRoll = cast_734_32(byte_str, i + 1, sizeof(float));
                i += sizeof(float);
            }
            case PNITraxDataID::kHeadingStatus: {
                data.kHeadingStatus = byte_str[i];
                i += sizeof(char);
            }
            case PNITraxDataID::kQuaternion: {
                for(auto &item: data.kQuaternion) {
                    item = cast_734_32(byte_str, i+1, sizeof(float));
                    i += sizeof(float);
                }
            }
            case PNITraxDataID::kTemperature: {
                data.kTemperature = cast_734_32(byte_str, i + 1, sizeof(float));
                i += sizeof(float);
            }
            case PNITraxDataID::kDistortion: {
                float buf = cast_734_32(byte_str, i + 1, sizeof(float));
                if (buf < 1e-5){
                    data.kDistortion = false;
                } else {
                    data.kDistortion = true;
                }
                i += sizeof(bool);
            }
            case PNITraxDataID::kCalStatus: {
                float buf = cast_734_32(byte_str, i + 1, sizeof(float));
                if (buf < 1e-5){
                    data.kCalStatus = false;
                } else {
                    data.kCalStatus = true;
                }
                i += sizeof(bool);
            }
//            case PNITraxDataID::kAccelX: {
//                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
//                i += sizeof(float);
//            }
//            case PNITraxDataID::kAccelY: {
//                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
//                i += sizeof(float);
//            }
//            case PNITraxDataID::kAccelZ: {
//                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
//                i += sizeof(float);
//            }
//            case PNITraxDataID::kMagX: {
//                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
//                i += sizeof(float);
//            }
//            case PNITraxDataID::kMagY: {
//                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
//                i += sizeof(float);
//            }
//            case PNITraxDataID::kMagZ: {
//                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
//                i += sizeof(float);
//            }
//            case PNITraxDataID::kGyroX: {
//                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
//                i += sizeof(float);
//            }
//            case PNITraxDataID::kGyroY: {
//                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
//                i += sizeof(float);
//            }
//            case PNITraxDataID::kGyroZ: {
//                data.kHeading = cast_734_32(byte_str, i + 1, sizeof(float));
//                i += sizeof(float);
//            }
            default:
                std::cerr << "ERROR: no one ID was found" << std::endl;
        }
    }
}

void test1() {
    size_t inputLen = 12;
    char rawInput[inputLen];
    rawInput[0] = 0x05;
    rawInput[1] = 0x3F;
    rawInput[2] = 0x80;
    rawInput[3] = 0x00;
    rawInput[4] = 0x00;
    rawInput[5] = 0x09;
    rawInput[6] = 0x01;
    rawInput[7] = 0x1C;
    rawInput[8] = 0x40;
    rawInput[9] = 0x00;
    rawInput[10] = 0x00;
    rawInput[11] = 0x00;
    PNITraxData data{};

    get_PNITraxData_from_msg(rawInput, inputLen, data);
    std::cout << data << std::endl;
}
int main() {

    auto data = std::make_shared<PNITraxData>();
    data->kGyroX = 1.f;
    std::cout << *data << std::endl;
    test1();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
