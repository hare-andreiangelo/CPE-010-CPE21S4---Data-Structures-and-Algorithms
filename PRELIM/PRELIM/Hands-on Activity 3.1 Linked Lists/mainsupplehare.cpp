#include <iostream>
#include <string>
#include "suppleplaylist.h"

int main()
{
    Playlist<std::string>* head = nullptr;

    // Create Playlist
    insertSong(std::string("Pusong Bato"), &head);
    insertSong(std::string("Digi Digi Dong"), &head);
    insertSong(std::string("Hawak mo ang beat"), &head);

    std::cout << "Testing the PlayAllSongs Function" << std::endl;
    playAllSongs(head);

    // Insert Song
    std::cout << "Testing the InsertSong Function" << std::endl;
    insertSong(std::string("Daddy's Home"), &head);
    playAllSongs(head);

    // Current song
    Playlist<std::string>* currentSong = head;

    // Next Song
    std::cout << "Testing the NextSong Function" << std::endl;
    nextSong(&currentSong);
    std::cout << "Current Song: " << currentSong->song << std::endl;

    // Previous Song
    std::cout << "Testing the PreviousSong Function" << std::endl;
    previousSong(head, &currentSong);
    std::cout << "Current Song: " << currentSong->song << std::endl;

    // Remove Song
    std::cout << "Testing the RemoveSong Function" << std::endl;
    removeSong(std::string("Digi Digi Dong"), &head);
    playAllSongs(head);

    // Play All Songs
    std::cout << "Testing the PlayAllSongs Function" << std::endl;
    playAllSongs(head);

    return 0;
}