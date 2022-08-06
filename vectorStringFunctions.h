//
// Created by Eli Calabrese on 7/25/2022.
//

#ifndef MUSICELO_VECTORSTRINGFUNCTIONS_H
#define MUSICELO_VECTORSTRINGFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <vector>
#include "song.h"
#include <sstream>
std::vector<std::string> split(std::string in);

template<typename F, typename S>
bool is_in(const F& valueToFind, S& vals_to_search) {
//    bool returnVal = false;
    auto itr = vals_to_search.begin();
    for(; itr != vals_to_search.end(); ++itr){
        if (valueToFind == *itr){
            return true;
        }
    }

    return false;
}
#endif //MUSICELO_VECTORSTRINGFUNCTIONS_H
