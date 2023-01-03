//
// Created by Eli Calabrese on 7/25/2022.
//

#ifndef MUSICELO_SONGELO_H
#define MUSICELO_SONGELO_H
#include <vector>
#include <fstream>
#include "song.h"

namespace elo{
    class songElo {
    public:
        std::vector<elo::song> fillVector(std::ifstream& in);
        void run();
        elo::song getSongAt(int i);

    private:
        std::vector<elo::song> songs;
        std::vector<elo::song> lastUsedSongs;
        std::string path;

        void printMenu();

        char getChoice();

        void compare();

        void doOption(char choice);

        void compare(song &song1, int i);

        void compare(int i);

        void compare(song &song1, song &song2, int i);

        void addSong();

        song & getRandomSong();

        void setNewElo(song &winner, song &loser);

        std::pair<song &, song &> getTwoRandomSongs();

        int getRandomIndex();

        void printVectors();

        void updateFile();

        song & getSongThatIsNotThisSong(song song1);

        void removeSong();

        song &getSongThatIsNotThisSong(song song1, song song2);

        song &getSongThatHasNotBeenUsed();

        std::pair<song &, song &> getTwoRandomSongsThatHaveNotBeenUsed();
    };
}



#endif //MUSICELO_SONGELO_H
