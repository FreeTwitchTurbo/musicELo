#include <iostream>
#include <fstream>
#include "song.h"
#include "songElo.h"
#include "vectorStringFunctions.h"


/* options
 * add a song
 * remove a song
 * compare songs
 * view leaderboard
 * quit
 * */


int main() {
    elo::songElo program;
    program.run();
    return 0;
}


