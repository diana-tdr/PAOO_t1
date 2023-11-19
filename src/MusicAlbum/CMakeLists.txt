add_library(MusicAlbum STATIC MusicAlbum.cpp)
add_library(VinylAlbum STATIC VinylAlbum.cpp)
add_library(DigitalAlbum STATIC DigitalAlbum.cpp)

target_include_directories(MusicAlbum PUBLIC "./")