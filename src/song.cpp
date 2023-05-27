//
// Created by Eli Calabrese on 7/22/2022.
//

#include "song.h"
elo::song::song(const std::string &name, const std::string &artist, int elo) : name(name), artist(artist), elo(elo) {}

const std::string &elo::song::getName() const {
    return name;
}

const std::string &elo::song::getArtist() const {
    return artist;
}

double elo::song::getElo() const {
    return elo;
}

void elo::song::setElo(double elo) {
    song::elo = elo;
}

bool elo::song::operator==(const elo::song &rhs) const {
    return (rhs.getArtist() == this->getArtist() and rhs.getName() == this->getName());
}
bool elo::song::operator!=(const elo::song &rhs) const {
    return !(rhs == *this);
}

bool elo::song::operator<(const elo::song &rhs) const {
    if(this->elo != rhs.elo){
        return this->elo < rhs.elo;
    } else if (this->name != rhs.name){
        return this->name < rhs.name;
    }
    else {
        return this->artist < rhs.artist;
    }
}

bool elo::song::operator>(const elo::song &rhs) const {
    return !(*this < rhs);
}

bool elo::song::operator<=(const elo::song &rhs) const {
    return *this < rhs or *this == rhs;
}

//std::ostream& elo::song::operator<<(std::ostream& out, const elo::song& song){
//
//}
