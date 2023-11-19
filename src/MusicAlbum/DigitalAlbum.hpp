#ifndef DIGITALALBUM_HPP
#define DIGITALALBUM_HPP

#include "MusicAlbum.hpp"

namespace MusicLibrary {

class DigitalAlbum : public MusicAlbum {
public:
    DigitalAlbum(const std::string& albumTitle, const std::string& artist, int releaseYear, int downloadCount);
    ~DigitalAlbum();

    void setDownloadCount(int downloadCount);
    int getDownloadCount() const;

private:
    int downloadCount;
};

}

#endif
