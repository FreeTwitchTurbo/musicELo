//
// Created by Eli Calabrese on 7/26/2022.
//

#include <string>
#include <iostream>
#include <sstream>
#include "inputValidation.h"


char get_valid_char() {
    std::string line;
    while (true) {
        std::getline(std::cin, line); //grabs the entire line
        std::stringstream line2parse(line);
        char num;
        line2parse >> num;
        if (line2parse) { //if I was able to read the number
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse) { //if there is nothing left we will fail to read it
                return num;
            }
        }
    }
}


int get_valid_int() {
    std::string line;
    while (true) {
        std::getline(std::cin, line); //grabs the entire line
        std::stringstream line2parse(line);
        int num;
        line2parse >> num;
        if (line2parse) { //if I was able to read the number
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse) { //if there is nothing left we will fail to read it
                return num;
            }
        }
    }
}