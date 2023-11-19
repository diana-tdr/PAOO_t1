#include "VinylAlbum.hpp"
#include <iostream>

namespace MusicLibrary {

VinylAlbum::VinylAlbum(const std::string& albumTitle, const std::string& artist, int releaseYear, int rpm)
    : MusicAlbum(albumTitle, artist, releaseYear), rpm(rpm) {
    std::cout << "VinylAlbum constructor called\n";
}

VinylAlbum::~VinylAlbum() {
    std::cout << "VinylAlbum destructor called\n";
}

void VinylAlbum::setRPM(int rpm) {
    this->rpm = rpm;
}

int VinylAlbum::getRPM() const {
    return rpm;
}

}
