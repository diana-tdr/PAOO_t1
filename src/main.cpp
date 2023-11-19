#include "VinylAlbum.hpp"
#include "DigitalAlbum.hpp"
#include <iostream>

int main() {
    // Create instances of your classes
    MusicLibrary::MusicAlbum album1("Album1", "Artist1", 2020);
    album1.addTrack({"Track1", 180});
    album1.addTrack({"Track2", 200});

    MusicLibrary::VinylAlbum vinyl1("VinylAlbum1", "VinylArtist1", 2015, 33);
    vinyl1.addTrack({"VinylTrack1", 220});
    vinyl1.addTrack({"VinylTrack2", 240});

    MusicLibrary::DigitalAlbum digital1("DigitalAlbum1", "DigitalArtist1", 2018, 1000);
    digital1.addTrack({"DigitalTrack1", 260});
    digital1.addTrack({"DigitalTrack2", 280});

    // Display information using polymorphism
    std::cout << "Displaying MusicAlbum:\n";
    album1.displayAlbum();
    std::cout << "Total Duration: " << album1.getTotalDuration() << " seconds\n\n";

    std::cout << "Displaying VinylAlbum:\n";
    vinyl1.displayAlbum();
    std::cout << "RPM: " << vinyl1.getRPM() << "\nTotal Duration: " << vinyl1.getTotalDuration() << " seconds\n\n";

    std::cout << "Displaying DigitalAlbum:\n";
    digital1.displayAlbum();
    std::cout << "Download Count: " << digital1.getDownloadCount() << "\nTotal Duration: " << digital1.getTotalDuration() << " seconds\n\n";

    // Use overloaded copy and move assignment operators
    MusicLibrary::MusicAlbum albumCopy = album1;  // Copy assignment
    albumCopy.displayAlbum();

    MusicLibrary::MusicAlbum albumMove = std::move(album1);  // Move assignment
    albumMove.displayAlbum();

    MusicLibrary::VinylAlbum vinylCopy = vinyl1;  // Copy assignment
    vinylCopy.displayAlbum();

    MusicLibrary::DigitalAlbum digitalMove = std::move(digital1);  // Move assignment
    digitalMove.displayAlbum();

    return 0;
}
