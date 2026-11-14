// Version 2: input validation, random phrases, win rating by tries.
// Reconstructed from the chat log.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "games.h"

using namespace std;

void run_v2() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int target = (rand() % 100) + 1;
    int guess{ 0 };
    int tries{ 0 };

    vector<string> promptPhrases{
        "Try again: ",
        "Next guess: ",
        "What's your next attempt? ",
    };

    vector<string> tooHighPhrases{
        "Lower! Your guess is higher than my student loan debt. ",
        "Whoa, that's way too high. Dreaming big, aren't we? ",
        "Too high! The code is down here, not in the clouds. ",
        "Nah nah nah, too high. "
    };

    // As in the original, the missing comma after the third phrase joins
    // the third and fourth strings into one phrase.
    vector<string> tooLowPhrases{
        "Too low. Are you afraid of big numbers?",
        "Higher! My grandma can guess a bigger number than that.",
        "That's cute, but it's still too low."
        "How about guess higher? "
    };

    vector<string> averagePhrases{
        "Finally! I was starting to think you'd never get it.",
        "About time! You got it, but my cat could probably do it faster.",
        "You got it! But let's see if you can do better next time."
    };

    cout << "Welcome to Da Vinci Code" << endl;

    do {
        if (tries == 0)
            cout << "I'm thinking of a number between 1 and 100. Take a guess: ";
        else
            cout << promptPhrases.at(rand() % promptPhrases.size());

        // integer validation
        if (!(cin >> guess)) {
            cout << "Invalid input! Please enter a NUMBER.\n" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cin.ignore(100, '\n');

        // range validation
        if (guess < 1 || guess > 100) {
            cout << "Hey! I said between 1 and 100! This guess doesn't count.\n" << endl;
            continue;
        }

        tries++;

        if (guess > target) {
            cout << tooHighPhrases.at(rand() % tooHighPhrases.size()) << "\n" << endl;
        }
        else if (guess < target) {
            cout << tooLowPhrases.at(rand() % tooLowPhrases.size()) << "\n" << endl;
        }
        else if (guess == target && tries <= 3) {
            cout << "Omg you can read my mind!" << "\n" << endl;
        }
        else if (guess == target && tries > 3) {
            cout << averagePhrases.at(rand() % averagePhrases.size()) << endl;
            cout << "You cracked the code in " << tries << " tries. " << endl;
        }

    } while (guess != target);
}
