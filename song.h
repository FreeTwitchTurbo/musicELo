//
// Created by Eli Calabrese on 7/22/2022.
//

#ifndef MUSICELO_SONG_H
#define MUSICELO_SONG_H
#include <string>
namespace elo{
    class song {
    friend std::ostream& operator<<(std::ostream& out, const elo::song& song){
        std::string dash(" - ");
        out << song.getArtist() << dash << song.getName(); //i hate cpp
        return out;
    };
    public:
        bool operator==(const elo::song& rhs) const;
        bool operator!=(const elo::song& rhs) const;
        bool operator<(const elo::song& rhs) const;
        song(const std::string &name, const std::string &artist, int elo);
//        void compare;
    private:
        std::string name;
        std::string artist;
        double elo;
    public:
        const std::string &getName() const;

        const std::string &getArtist() const;

        double getElo() const;

        void setElo(double elo);

    };
//    std::ostream& operator<<(std::ostream& os, const elo::song&);

//    std::ostream &elo::operator<<(std::ostream &os, const elo::song &song) {
//
//    }



}



#endif //MUSICELO_SONG_H
