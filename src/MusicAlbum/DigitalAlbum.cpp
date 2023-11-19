#include "DigitalAlbum.hpp"
#include <iostream>

namespace MusicLibrary {

DigitalAlbum::DigitalAlbum(const std::string& albumTitle, const std::string& artist, int releaseYear, int downloadCount)
    : MusicAlbum(albumTitle, artist, releaseYear), downloadCount(downloadCount) {
    std::cout << "DigitalAlbum constructor called\n";
}

DigitalAlbum::~DigitalAlbum() {
    std::cout << "DigitalAlbum destructor called\n";
}

void DigitalAlbum::setDownloadCount(int downloadCount) {
    this->downloadCount = downloadCount;
}

int DigitalAlbum::getDownloadCount() const {
    return downloadCount;
}

}
