//
// Created by Eli on 5/24/2023.
//
#include "gtest/gtest.h"
#include "song.h"
#include <random>
#include <algorithm>
#include "songElo.h"
#include "songEloTestable.h"

#include <fstream>


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
        ASSERT_TRUE(previous.getElo() <= currentSong.getElo() or previous.getArtist() <= currentSong.getArtist() or previous.getName() <= currentSong.getName());
        previous = currentSong;
    }
    // song1 should be less then song2 as a
}

TEST(testSongElo, testFillVector){
    auto program = elo::songElo();
    std::ofstream tempFile("temp.txt");
    std::vector<elo::song> controlVector = {elo::song("jimmy","john",1000),elo::song("jee","the",400),elo::song("aintThatJust","theWay",21)};
    tempFile << "jimmy;john;1000\njeee;the;400\naintThatJust;theWay;21\n";
    tempFile.close();

    std::ifstream tempWrite("temp.txt");
    auto songs = program.fillVector(tempWrite);
    tempWrite.close();

    ASSERT_EQ(songs.size(), 3);
    ASSERT_EQ(songs,controlVector);
}

TEST(SongEloTest, SetNewEloTest) {
    elo::songElo elo;
    elo::song winner("Song1", "Artist1", 1000);
    elo::song loser("Song2", "Artist2", 2000);

    // Call the setNewElo function
    elo.setNewElo(winner, loser);

    // Assert that the elo values are updated correctly
    EXPECT_EQ(winner.getElo(), 1100);
    EXPECT_EQ(loser.getElo(), 1900);
}

TEST(SongEloTest, GetSongThatHasNotBeenUsedTest) {
    elo::songEloTestable elo;
    elo::song song1("Song1", "Artist1", 1000);
    elo::song song2("Song2", "Artist2", 2000);
    elo::song song3("Song3", "Artist3", 3000);

    // Add the songs to the songElo object
    elo.push_back(song1);
    elo.push_back(song2);
    elo.push_back(song3);

    // Call the getSongThatHasNotBeenUsed function
    elo::song& result1 = elo.getSongThatHasNotBeenUsedT();
    elo::song& result2 = elo.getSongThatHasNotBeenUsedT();
    elo::song& result3 = elo.getSongThatHasNotBeenUsedT();

    // Assert that the returned songs are different from each other
    EXPECT_NE(result1.getName(), result2.getName());
    EXPECT_NE(result1.getName(), result3.getName());
    EXPECT_NE(result2.getName(), result3.getName());
}
