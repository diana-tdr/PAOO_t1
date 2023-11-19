#ifndef MUSICALBUM_HPP
#define MUSICALBUM_HPP
#include <string>
#include "IMusicAlbum.hpp"

namespace MusicLibrary {

class MusicAlbum : public IMusicAlbum {
public:
    MusicAlbum(const std::string& albumTitle, const std::string& artist, int releaseYear);
    MusicAlbum(const MusicAlbum& other);
    MusicAlbum& operator=(const MusicAlbum& other);  // Copy assignment operator
    MusicAlbum(MusicAlbum&& other);
    MusicAlbum& operator=(MusicAlbum&& other);  // Move assignment operator
    virtual ~MusicAlbum();

    void addTrack(const Track& track);
    void displayAlbum() const;
    Track* searchTrack(const std::string& title) const;
    void updateTrack(const std::string& title, const std::string& newTitle, int newDurationInSeconds);
    void deleteTrack(const std::string& title);
    int getTotalDuration() const;

private:
    std::string title;
    std::string artist;
    int releaseYear;
    int durationInSeconds;
    Track** tracks;
    int numTracks;
};

}

#endif
