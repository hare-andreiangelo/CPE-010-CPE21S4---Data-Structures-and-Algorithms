#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sorting.h"

const int maxSize = 100;

void displayArr(int arr[]);
void countVotes(int arr[]);

int main()
{
    int unsortedArr[maxSize];

    srand(time(0));

    for (int i = 0; i < maxSize; i++)
    {
        unsortedArr[i] = rand() % 5 + 1;
    }

    std::cout << "\nOriginal Array:\n";
    displayArr(unsortedArr);

    std::cout << "\nBubble Sort testing:\n";
    bubbleSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
 
    std::cout << "\nVote Count:\n";
    countVotes(unsortedArr);

    return 0;
}

void displayArr(int arr[])
{
    for (int i = 0; i < maxSize; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void countVotes(int arr[])
{
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

    for (int i = 0; i < maxSize; i++)
    {
        if (arr[i] == 1)
        {
            count1++;
        }
        else if (arr[i] == 2)
        {
            count2++;
        }
        else if (arr[i] == 3)
        {
            count3++;
        }
        else if (arr[i] == 4)
        {
            count4++;
        }
        else if (arr[i] == 5)
        {
            count5++;
        }
    }

    std::cout << "Candidate 1 - Bo Dalton Capistrano: "
              << count1 << " votes" << std::endl;

    std::cout << "Candidate 2 - Cornelius Raymon Agustín: "
              << count2 << " votes" << std::endl;

    std::cout << "Candidate 3 - Deja Jayla Bañaga: "
              << count3 << " votes" << std::endl;

    std::cout << "Candidate 4 - Lalla Brielle Yabut: "
              << count4 << " votes" << std::endl;

    std::cout << "Candidate 5 - Franklin Relano Castro: "
              << count5 << " votes" << std::endl;

    int highest = count1;
    int winner = 1;

    if (count2 > highest)
    {
        highest = count2;
        winner = 2;
    }

    if (count3 > highest)
    {
        highest = count3;
        winner = 3;
    }

    if (count4 > highest)
    {
        highest = count4;
        winner = 4;
    }

    if (count5 > highest)
    {
        highest = count5;
        winner = 5;
    }

    std::cout << "\nWinning Candidate: Candidate "
              << winner << std::endl;

    std::cout << "Winning Votes: "
              << highest << std::endl;
}