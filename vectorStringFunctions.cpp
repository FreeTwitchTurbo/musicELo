//
// Created by Eli Calabrese on 7/25/2022.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "song.h"
#include <sstream>
std::vector<std::string> split(std::string in){
    std::stringstream sstream(in);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(sstream, segment, ';'))
    {
        seglist.push_back(segment);
    }
    return seglist;
}



#include "vectorStringFunctions.h"
