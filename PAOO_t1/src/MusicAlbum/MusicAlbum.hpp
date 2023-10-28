#ifndef MUSICALBUM_HPP
#define MUSICALBUM_HPP
#include <string>

struct Track {
    std::string title;
    int durationInSeconds;
};

class MusicAlbum {
public:
    MusicAlbum(const std::string& albumTitle, const std::string& artist, int releaseYear);
    MusicAlbum(const MusicAlbum& other);
    MusicAlbum(MusicAlbum&& other);
    ~MusicAlbum();

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

#endif
