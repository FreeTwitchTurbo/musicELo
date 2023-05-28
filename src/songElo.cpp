//
// Created by Eli Calabrese on 7/25/2022.
//

#include "songElo.h"
#include <fstream>
#include <iostream>
#include "vectorStringFunctions.h"
#include "inputValidation.h"
#include <random>
#include <utility>
#include <algorithm>

void compare(elo::song song1, int i);

bool compareSongOrder(elo::song song1, elo::song song2){
    return (song1.getElo() < song2.getElo());
}

std::vector<elo::song> elo::songElo::fillVector(std::ifstream& in){
    std::string line;
    std::vector<elo::song>songsFromFile;
    while(std::getline(in, line)) {
        auto components = split(line);
        if(components.size() == 3) {
            elo::song song(components[1],components[0],std::stoi(components[2]));
            songsFromFile.push_back(song);
        }
    }
    return songsFromFile;
}

void elo::songElo::printMenu(){
    std::cout << "Please select an option" << std::endl;
    std::cout << "A: add a song" << std::endl << "R: Remove a song" << std::endl << "C: compare and update your rankings" << std::endl << "P: import a song or playlist from SoundCloud"
              << std::endl << "V: View your rankings" << std::endl << "U: Update your save file" << std::endl << "Q: quit" << std::endl;
}

void elo::songElo::doOption(char choice) {
    switch(choice){
        case 'A':
            addSong();
            break;
        case 'R':
            removeSong();
            break;
        case 'C':
            compare();
            break;
        case 'V':
            printVectors();
            break;
        case 'U':
            updateFile();
            std::cout << "songs.txt updated" << std::endl;
            break;
        case 'P':
            std::string url;
            std::cout << "Enter your soundcloud playlist or song url (copy url do not use the 'copy link' button): ";
            std::cin >> url;
            getSongsFromSoundcloud(url);
    }
}

void elo::songElo::getSongsFromSoundcloud(std::string url){

    std::ofstream tempFile("temp.txt");
    auto passStr = "python ../../src/webScrape.py "+url;


    system(passStr.c_str());
    tempFile.close();



    std::ifstream tempFileIstream("temp.txt");
    auto songsFromFile = this->fillVector(tempFileIstream);
    this->songs.insert(this->songs.end(), songsFromFile.begin(), songsFromFile.end());
    tempFileIstream.close();
    std::remove("temp.txt");

}

void elo::songElo::removeSong() {
    printVectors();
    std::cout << "Input the index of the song you would like to remove" << std::endl;
    int index;
    do {
        index = get_valid_int();
    } while(!(index <= (int)songs.size() and index > 0)); //gotta change this
    std::cout << "Removing " << songs.at(index-1) << std::endl;
    songs.erase(songs.begin() + index - 1);

}

void elo::songElo::updateFile() {
    std::ofstream file;
    file.open(("../songs.txt"), std::ofstream::trunc);
    for(int i = 0; i < (int)this->songs.size(); ++i) {
        file << getSongAt(i).getArtist() << ';' << getSongAt(i).getName() << ';' << getSongAt(i).getElo() << std::endl;
    }
    file.close();
}

elo::song elo::songElo::getSongAt(int i) {
    return this->songs.at(i);
}

void elo::songElo::compare() {
    std::cout << "How many times would you like to do battle?: ";
    int degree = get_valid_int();
    auto newSongs = getTwoSongsThatHaveNotBeenUsed();
//    newSongs.first.setElo(2);
    compare(newSongs.first, newSongs.second, degree);
}


void elo::songElo::addSong() {
    std::string artistName, songName;
    std::cout << "Enter the song name" << std::endl;
    std::getline(std::cin, songName);
    std::cout << "Enter the artist's name" << std::endl;
    std::getline(std::cin, artistName);
    auto newSong = elo::song(songName, artistName, 2500);

    std::cout << "Added " << newSong << " with a default elo of 2500" << std::endl;
    std::cout << "Calibrating new song..." << std::endl;

    if(this->songs.size() < 10) {
        compare(newSong, this->songs.size());
    } else {
        compare(newSong, 10);
    }
    lastUsedSongs.clear();
    songs.push_back(newSong);
    std::sort(this->songs.begin(), this->songs.end(), compareSongOrder);
}

void elo::songElo::setNewElo(song &winner, song &loser) {
    double ratio = loser.getElo()/winner.getElo();
    double change = 100 * ratio;
    winner.setElo(winner.getElo() + change);
    loser.setElo(loser.getElo() - change);
//    return elo1 + 5000 * ()
}

void elo::songElo::compare(song &song1, song &song2, int i) {
        if(lastUsedSongs.size() == songs.size()){
            std::cout << "you ran out of songs!!! add some more dummy !!" << std::endl;
            lastUsedSongs.clear();
            return;
        }

        if(i < 1 and lastUsedSongs.size() != songs.size()){
            lastUsedSongs.clear();
            return;
        }
        std::cout << "Which song is the better listen?" << std::endl << song1.getName() << " by " << song1.getArtist()
                  << " (1)" << std::endl << song2.getName() << " by " << song2.getArtist()
                  << " (2)" << std::endl << "Enter (1) or (2): ";
        int result;
        do {
            result = get_valid_int();
        } while (!(result >= 0 and result < 3));
        if (result == 0) {
            setNewElo(song1, song2); //winner goes first
        } else {
            setNewElo(song2, song1);
        }

        std::cout << song1 << "'s new elo is " << song1.getElo() << std::endl <<
                  song2 << "'s new elo is " << song2.getElo() << std::endl;
        auto newSongs = getTwoSongsThatHaveNotBeenUsed();
    compare(newSongs.first, newSongs.second, i-1);
}

elo::song& elo::songElo::getRandomSong() {
    int index = getRandomIndex();
    return this->songs.at(index);
}

int elo::songElo::getRandomIndex() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, songs.size()-1); // define the range
    auto index = distr(gen);
    return index;
}

std::pair<elo::song&, elo::song&> elo::songElo::getTwoSongsThatHaveNotBeenUsed() {
    auto& song1 = getSongThatHasNotBeenUsed();
    auto& song2 = getSongThatHasNotBeenUsed();
    std::pair<elo::song&,elo::song&> returnVal {song1,song2};
    return returnVal;
}

elo::song & elo::songElo::getSongThatHasNotBeenUsed() {
    /*
     * takes an element from the song vector that is not in lastUsedSongs
     * adds that element to lastUsedSongs and returns a reference
     */

    auto index = getRandomIndex();
    while(is_in(songs.at(index), lastUsedSongs)) {
        index = getRandomIndex();
    }

    lastUsedSongs.push_back(songs.at(index));
    std::sort(lastUsedSongs.begin(),lastUsedSongs.end(), compareSongOrder);
    auto& ref = songs.at(index);
    return ref;
}

elo::song & elo::songElo::getSongThatIsNotThisSong(elo::song song1,elo::song song2) {
    auto index = getRandomIndex();
    while(song1 == songs.at(index)) {
        index = getRandomIndex();
    }
    auto& ref = songs.at(index);
    return ref;
}

void elo::songElo::compare(song &song1, int i) {
    int result;
        if(i < 1) {
            return;
        }

        if(lastUsedSongs.size() == songs.size()){
            std::cout << "you ran out of songs!!! add some more dummy !!" << std::endl;
            lastUsedSongs.clear();
            return;
        }

        auto& song2 = getSongThatHasNotBeenUsed();

        std::cout << "Which song is the better listen?" << std::endl << song1.getName() << " by " << song1.getArtist()
                  << " (1)" << std::endl << song2.getName() << " by " << song2.getArtist()
                  << " (2)" << std::endl;
        do {
//
            std::cout << "Enter (1) or (2):" << std::endl;
            result = get_valid_int();
//            std::cin >> result;
        } while (!(result >= 1 and result < 3));

        if (result == 1) {
            setNewElo(song1, song2); //winner goes first
        } else {
            setNewElo(song2, song1);
        }

        std::cout << song1 << "'s new elo is " << song1.getElo() << std::endl <<
                  song2 << "'s new elo is " << song2.getElo() << std::endl;
//    }
        compare(song1, i-1);
}

char elo::songElo::getChoice() {
    std::vector<char> validChoices{'A','C','P','Q','R','U','V'};
    char choice;
    do{
        choice = get_valid_char();
        choice = toupper(choice);
        if(!is_in(choice,validChoices)) {
            std::cout << "I don't think " << choice << " was a valid option. Please try again" << std::endl;
        }
    }while(!is_in(choice,validChoices));

    return choice;
}

void elo::songElo::run() {
    std::ifstream newPath("../songs.txt");
    char choice;

    if(!newPath.is_open()) {
        std::cout << "no songs.txt file found, creating one";
        std::ofstream o("../songs.txt");
        //maybe i can add an option to create a songs file if none is
//        exit(1);
    }
    this->songs = fillVector(newPath);
    newPath.close();


    std::cout << "Hi!! Welcome to SONG ELO RANKER 9000" << std::endl;
    do {
        printMenu();
        choice = getChoice();
//        std::cout << "your choice was " << choice;
        doOption(choice);
    }while(choice != 'Q');

    updateFile();
}

void elo::songElo::printVectors() {
     std::sort(this->songs.begin(), this->songs.end(), compareSongOrder);
     for(int i = this->songs.size()-1; i >= 0; --i) {
         std::cout << (songs.size()-i) << ") " << songs.at(i) << " (" << songs.at(i).getElo() << ")" << std::endl;
     }
}



