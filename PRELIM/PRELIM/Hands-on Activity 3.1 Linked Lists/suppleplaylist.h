#ifndef SUPPLEPLAYLIST_H
#define SUPPLEPLAYLIST_H

#include <iostream>
#include <string>

template <typename T>
class Playlist
{
public:
    T song;
    Playlist<T>* next;
};

// Create a new song node
template <typename T>
Playlist<T>* createSong(T newSong)
{
    Playlist<T>* newNode = new Playlist<T>;
    newNode->song = newSong;
    newNode->next = newNode;

    return newNode;
}

// Insert song at the end
template <typename T>
void insertSong(T newSong, Playlist<T>** head)
{
    Playlist<T>* newNode = createSong(newSong);

    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    Playlist<T>* current = *head;

    while (current->next != *head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = *head;
}

// Remove a song
template <typename T>
void removeSong(T findSong, Playlist<T>** head)
{
    if (*head == nullptr)
    {
        return;
    }

    Playlist<T>* current = *head;
    Playlist<T>* previous = nullptr;

    // Delete first node
    if (current->song == findSong)
    {
        if (current->next == *head)
        {
            delete current;
            *head = nullptr;
            return;
        }

        Playlist<T>* last = *head;

        while (last->next != *head)
        {
            last = last->next;
        }

        last->next = current->next;
        *head = current->next;

        delete current;
        return;
    }

    previous = current;
    current = current->next;

    while (current != *head)
    {
        if (current->song == findSong)
        {
            previous->next = current->next;
            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }
}

// Display playlist
template <typename T>
void playAllSongs(Playlist<T>* head)
{
    if (head == nullptr)
    {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    Playlist<T>* current = head;

    do
    {
        std::cout << current->song << std::endl;
        current = current->next;

    } while (current != head);
}

// Next song
template <typename T>
void nextSong(Playlist<T>** currentSong)
{
    if (*currentSong != nullptr)
    {
        *currentSong = (*currentSong)->next;
    }
}

// Previous song
template <typename T>
void previousSong(Playlist<T>* head, Playlist<T>** currentSong)
{
    if (head == nullptr || *currentSong == nullptr)
    {
        return;
    }

    Playlist<T>* temp = head;

    while (temp->next != *currentSong)
    {
        temp = temp->next;
    }

    *currentSong = temp;
}

#endif