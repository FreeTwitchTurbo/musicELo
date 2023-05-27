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
    if(vals_to_search.size() == 0){
        return false;
    }
//    bool returnVal = false;
    int low = 0;
    int high = vals_to_search.size();
    int mid;
    while(low != high) {
        mid = (low + high) / 2;
        if(vals_to_search.at(mid) == valueToFind){
            return true;
        } else if(valueToFind > vals_to_search.at(mid)){
            low = mid + 1;
        } else{
            high = mid;
        }
    }

    return false;
}


//bool binarySearch(std::vector<int> data, int value){
//    int low = 0;
//    int high = data.size();
//    while (low != high) {
//        int mid = (low+high)/2;
//        if(data.at(mid) == value) {
//            return true;
//        }else if(value > data.at(mid)){
//            low = mid + 1;
//        }
//        else                  // x is on the left side
//            high = mid;
//    }
//    return false;
//}

#endif //MUSICELO_VECTORSTRINGFUNCTIONS_H
