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

        void setNewElo(song &winner, song &loser);

    protected:
        std::vector<elo::song> songs;
        std::vector<elo::song> lastUsedSongs;
        std::string path;

        void printMenu();

        char getChoice();

        void compare();

        void doOption(char choice);

        void compare(song &song1, int i);

        void getSongsFromSoundcloud(std::string url);

        void compare(song &song1, song &song2, int i);

        void addSong();

        song & getRandomSong();

        int getRandomIndex();

        void printVectors();

        void updateFile();

        void removeSong();

        song &getSongThatIsNotThisSong(song song1, song song2);

        song &getSongThatHasNotBeenUsed();

        std::pair<song &, song &> getTwoSongsThatHaveNotBeenUsed();
    };
}



#endif //MUSICELO_SONGELO_H
