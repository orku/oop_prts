//
// Created by orku on 25.12.2021.
//
#include <iostream>
#include "missions/dive.h"
int main(){
    Dive dive(23, 0, 0);
    std::cout << dive.mission() << std::endl;
    return 0;
}