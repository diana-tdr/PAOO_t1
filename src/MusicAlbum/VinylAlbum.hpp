#ifndef VINYLALBUM_HPP
#define VINYLALBUM_HPP

#include "MusicAlbum.hpp"

namespace MusicLibrary {

class VinylAlbum : public MusicAlbum {
public:
    VinylAlbum(const std::string& albumTitle, const std::string& artist, int releaseYear, int rpm);
    ~VinylAlbum();

    void setRPM(int rpm);
    int getRPM() const;

private:
    int rpm;
};

}

#endif
