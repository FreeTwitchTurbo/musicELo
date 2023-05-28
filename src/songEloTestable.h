//
// Created by Eli on 5/28/2023.
//

#ifndef MUSICELO_SONGELOTESTABLE_H
#define MUSICELO_SONGELOTESTABLE_H
#include "songElo.h"
#include "song.h"

namespace elo {

    class songEloTestable : public elo::songElo {
    public:
        void push_back(elo::song song){
            songs.push_back(song);
        }
        elo::song& getSongThatHasNotBeenUsedT(){ // T for testing hehe
            return getSongThatHasNotBeenUsed();
        }
    };

}
#endif //MUSICELO_SONGELOTESTABLE_H
