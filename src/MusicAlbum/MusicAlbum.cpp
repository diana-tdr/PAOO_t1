#include "MusicAlbum.hpp"
#include <iostream>
#include <cstring>

namespace MusicLibrary {

MusicAlbum::MusicAlbum(const std::string& albumTitle, const std::string& artist, int releaseYear) {
    std::cout << "DEFAULT CONSTRUCTOR called\n";

    this->title = albumTitle;
    this->artist = artist;
    this->releaseYear = releaseYear;
    this->durationInSeconds = 0;
    this->tracks = nullptr;
    this->numTracks = 0;

    std::cout << "New object created:\n";
    displayAlbum();
}

MusicAlbum::MusicAlbum(const MusicAlbum& other) {
    std::cout << "COPY CONSTRUCTOR called " << other.title << std::endl;

    this->title = other.title;
    this->artist = other.artist;
    this->releaseYear = other.releaseYear;
    this->durationInSeconds = other.durationInSeconds;

    if (other.tracks) {
        this->tracks = new Track*[other.numTracks];
        this->numTracks = other.numTracks;
        for (int i = 0; i < numTracks; ++i) {
            this->tracks[i] = new Track;

            this->tracks[i]->title = other.tracks[i]->title;

            this->tracks[i]->durationInSeconds = other.tracks[i]->durationInSeconds;
        }
    } else {
        this->tracks = nullptr;
        this->numTracks = 0;
    }
}

MusicAlbum& MusicAlbum::operator=(const MusicAlbum& other) {
    if (this != &other) {
        // Release existing resources
        for (int i = 0; i < this->numTracks; ++i) {
            delete this->tracks[i];
        }
        delete[] this->tracks;

        // Copy data from the other object
        this->title = other.title;
        this->artist = other.artist;
        this->releaseYear = other.releaseYear;
        this->durationInSeconds = other.durationInSeconds;

        if (other.tracks) {
            this->tracks = new Track*[other.numTracks];
            this->numTracks = other.numTracks;
            for (int i = 0; i < numTracks; ++i) {
                this->tracks[i] = new Track;

                this->tracks[i]->title = other.tracks[i]->title;
                this->tracks[i]->durationInSeconds = other.tracks[i]->durationInSeconds;
            }
        } else {
            this->tracks = nullptr;
            this->numTracks = 0;
        }
    }
    std::cout << "COPY ASSIGNMENT OPERATOR called " << other.title << std::endl;
    return *this;
}

MusicAlbum::MusicAlbum(MusicAlbum&& other) {
    std::cout << "MOVE CONSTRUCTOR called " << other.title << std::endl;

    this->title = other.title;
    this->artist = other.artist;
    this->releaseYear = other.releaseYear;
    this->durationInSeconds = other.durationInSeconds;
    this->numTracks = other.numTracks;
    this->tracks = other.tracks;

    other.title.clear();
    other.artist.clear();
    other.releaseYear = 0;
    other.durationInSeconds = 0;
    other.numTracks = 0;
    other.tracks = nullptr;
}

MusicAlbum& MusicAlbum::operator=(MusicAlbum&& other) {
    if (this != &other) {
        // Release existing resources
        for (int i = 0; i < this->numTracks; ++i) {
            delete this->tracks[i];
        }
        delete[] this->tracks;

        // Move data from the other object
        this->title = std::move(other.title);
        this->artist = std::move(other.artist);
        this->releaseYear = other.releaseYear;
        this->durationInSeconds = other.durationInSeconds;
        this->numTracks = other.numTracks;
        this->tracks = other.tracks;

        // Reset the moved object
        other.title.clear();
        other.artist.clear();
        other.releaseYear = 0;
        other.durationInSeconds = 0;
        other.numTracks = 0;
        other.tracks = nullptr;
    }
    std::cout << "MOVE ASSIGNMENT OPERATOR called " << other.title << std::endl;
    return *this;
}

MusicAlbum::~MusicAlbum() {
    std::cout << "DESTRUCTOR called on MusicAlbum object with title <" << this->title << ">\n";

    for (int i = 0; i < this->numTracks; ++i) {
        delete this->tracks[i];
    }

    delete[] this->tracks;
}

void MusicAlbum::addTrack(const Track& track) {
    Track** newTracks = new Track*[numTracks + 1];
    for (int i = 0; i < numTracks; ++i) {
        newTracks[i] = tracks[i];
    }

    newTracks[numTracks] = new Track;
    newTracks[numTracks]->title = track.title;
    newTracks[numTracks]->durationInSeconds = track.durationInSeconds;

    delete[] tracks;

    tracks = newTracks;
    numTracks++;

    durationInSeconds += track.durationInSeconds;

    std::cout << "Track <" << track.title << "> added to album <" << this->title << ">" << std::endl;
}

void MusicAlbum::displayAlbum() const {
    std::cout << "\n\tTITLE: " << this->title << "\n\tARTIST: " << this->artist << "\n\tYEAR: " << this->releaseYear;
    if(this->numTracks) {
        std::cout << "\n\tTRACKS:\n";
        for (int i = 0; i < this->numTracks; ++i) {
            std::cout << "\t\t- " << this->tracks[i]->title << " (" << this->tracks[i]->durationInSeconds << " seconds)";
            if(i < this->numTracks - 1) {
                std::cout << "\n";
            }
        }
    }
    std::cout << "\n\tTOTAL DURATION: " << this->durationInSeconds << " seconds" << "\n\tNUMBER OF TRACKS: " << this->numTracks << "\n\n";
}

Track* MusicAlbum::searchTrack(const std::string& title) const {
    for (int i = 0; i < numTracks; ++i) {
        if (tracks[i]->title == title) {
            return tracks[i];
        }
    }

    return nullptr;
}

void MusicAlbum::updateTrack(const std::string& title, const std::string& newTitle, int newDurationInSeconds) {
    Track* trackToModify = searchTrack(title);

    if (trackToModify) {
        trackToModify->title = newTitle;
        trackToModify->durationInSeconds = newDurationInSeconds;

        std::cout << "Track <" << title << "> in album <" << this->title << "> updated to <" << newTitle << "> (" << newDurationInSeconds << " seconds)" << std::endl;
    } else {
        std::cout << "Track <" << title << "> not found in album <" << this->title << ">. Update failed." << std::endl;
    }
}

void MusicAlbum::deleteTrack(const std::string& title) {
    Track* trackToDelete = searchTrack(title);

    if (trackToDelete) {
        int indexToDelete = -1;
        for (int i = 0; i < numTracks; ++i) {
            if (tracks[i] == trackToDelete) {
                indexToDelete = i;
                break;
            }
        }

        if (indexToDelete != -1) {
            delete tracks[indexToDelete];

            for (int j = indexToDelete; j < numTracks - 1; ++j) {
                tracks[j] = tracks[j + 1];
            }

            numTracks--;
            durationInSeconds -= trackToDelete->durationInSeconds;

            std::cout << "Track <" << title << "> in album <" << this->title << "> deleted." << std::endl;
        }
    } else {
        std::cout << "Track <" << title << "> not found in album <" << this->title << ">. Deletion failed." << std::endl;
    }
}

int MusicAlbum::getTotalDuration() const {
    return this->durationInSeconds;
}

}
