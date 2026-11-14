// Version 1: core gameplay + range check (1-100).
// Reconstructed from the chat log.
// Known limitation (fixed in v2): typing a non-number makes the loop spin forever.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "games.h"

using namespace std;

void run_v1() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int target = (rand() % 100) + 1;
    int guess{ 0 };
    int tries{ 0 };

    cout << "Welcome to Da Vinci Code" << endl;

    do {
        cout << "I'm thinking of a number between 1 and 100. Take a guess: ";
        cin >> guess;

        // range validation
        if (guess < 1 || guess > 100) {
            cout << "Hey! I said between 1 and 100! This guess doesn't count.\n" << endl;
            continue;
        }

        tries++;

        if (guess > target)
            cout << "Nah nah nah, too high. \n" << endl;
        else if (guess < target)
            cout << "How about guess higher? \n" << endl;
        else
            cout << "Omg you can read my mind! \n" << endl;

    } while (guess != target);
}
