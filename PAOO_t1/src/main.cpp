#include "MusicAlbum.hpp"
#include <iostream>
#include <vector>

int main() {
    MusicAlbum album1("MusicAlbum Title 1", "Artist 1", 2020);
    album1.addTrack({"Song 1", 180});
    album1.addTrack({"Song 2", 210});

    MusicAlbum album2("MusicAlbum Title 2", "Artist 2", 2018);
    album2.addTrack({"Track 1", 240});
    album2.addTrack({"Track 2", 190});

    std::cout << "MusicAlbum 1:\n";
    album1.displayAlbum();

    std::cout << "\nAlbum 2:\n";
    album2.displayAlbum();

    MusicAlbum album1Copy = album1;
    std::cout << "\nCopy of MusicAlbum 1:\n";
    album1Copy.displayAlbum();

    album1Copy.updateTrack("Song 1", "New Song 1 Title", 240);
    album1Copy.deleteTrack("Song 2");

    std::cout << "\nALBUM 1:\n";
    album1.displayAlbum();
    std::cout << "\nALBUM 1 COPY:\n";
    album1Copy.displayAlbum();

    std::vector<MusicAlbum> albums;

    albums.push_back(MusicAlbum("MusicAlbum Title 3", "Artist 3", 1998));
    std::cout<< "-------------------------------------------------------\n";
    albums.push_back(MusicAlbum("MusicAlbum Title 4", "Artist 4", 1971));
    std::cout<< "-------------------------------------------------------\n";

    return 0;
}
