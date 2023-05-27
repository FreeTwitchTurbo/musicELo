//
// Created by Eli on 5/24/2023.
//
#include "gtest/gtest.h"
#include "song.h"
#include <random>
#include <algorithm>

TEST(testSongs, testLessThan){

    std::vector<elo::song> list;
    int numSongs = 50;
    for (int i = 0; i < numSongs; ++i) {
        char name = 'a' + rand()%26; // get random character
        char artist = 'a' + rand()%26; // get random character
        auto song1 = elo::song(std::to_string(name),std::to_string(artist),rand());
    }
    std::sort(list.begin(), list.end());

    auto previous = elo::song("z","z",0);

    for (auto currentSong : list){
        ASSERT_TRUE(previous <= currentSong);
        ASSERT_TRUE(previous.getElo() <= currentSong.getElo())

        previous = currentSong;
    }
    // song1 should be less then song2 as a
}