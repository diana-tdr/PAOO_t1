#pragma once
#include <string>


struct Track {
    std::string title;
    int durationInSeconds;
};

class IMusicAlbum {
public:
    virtual void addTrack(const Track& track) = 0;
    virtual void displayAlbum() const = 0;
    virtual Track* searchTrack(const std::string& title) const = 0;
    virtual void updateTrack(const std::string& title, const std::string& newTitle, int newDurationInSeconds) = 0;
    virtual void deleteTrack(const std::string& title) = 0;
    virtual int getTotalDuration() const = 0;
};
