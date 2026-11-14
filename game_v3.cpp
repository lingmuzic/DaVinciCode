// Version 3: near-miss hints (within 5), no back-to-back repeated phrases,
// tries count shown at the end. Reconstructed from the chat log; the
// no-repeat logic is an assumption (see notes in chat).

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "games.h"

using namespace std;

// Picks a random index from a list, different from the previous one.
// Returns the new index and stores it in lastIdx.
static int pickNoRepeat(size_t size, int& lastIdx) {
    int newIndex;
    if (size <= 1) {            // nothing to avoid if there is only one phrase
        newIndex = 0;
    } else {
        do {
            newIndex = rand() % static_cast<int>(size);
        } while (newIndex == lastIdx);
    }
    lastIdx = newIndex;
    return newIndex;
}

void run_v3() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int target = (rand() % 100) + 1;
    int guess{ 0 };
    int tries{ 0 };

    bool debugMode = false;   // set to true to see the secret number while testing
    if (debugMode) {
        cout << " >>> DEBUG MODE: The secret number is " << target << " <<<" << endl;
    }

    // last used phrase index for each category (-1 = none yet)
    int lastPromptIdx = -1;
    int lastHighIdx = -1;
    int lastNearHighIdx = -1;
    int lastLowIdx = -1;
    int lastNearLowIdx = -1;

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

    vector<string> nearTooHighPhrases{
        "So close! You're breathing down the neck of the code. Just a bit lower.",
        "Oof, almost! You're just a tiny bit too high.",
        "One small step down, and you might just have it!"
    };

    // NOTE: in your paste there was no comma after the third phrase, so the
    // third and fourth strings were joined into one phrase. Kept as in the
    // original; add a comma after "...still too low." if you want 4 phrases.
    vector<string> tooLowPhrases{
        "Too low. Are you afraid of big numbers?",
        "Higher! My grandma can guess a bigger number than that.",
        "That's cute, but it's still too low."
        "How about guess higher? "
    };

    vector<string> nearTooLowPhrases{
        "So close! A little bit more...",
        "Almost there! You're just a hair too low.",
        "You're right on the doorstep! Just a nudge higher."
    };

    vector<string> averagePhrases{
        "Finally! I was starting to think you'd never get it.",
        "About time! You got it, but my cat could probably do it faster.",
        "You got it! But let's see if you can do better next time."
    };

    cout << "Welcome to Da Vinci Code" << endl;

    do {
        if (tries == 0) {
            cout << "I'm thinking of a number between 1 and 100. Take a guess: ";
        } else {
            cout << promptPhrases.at(pickNoRepeat(promptPhrases.size(), lastPromptIdx));
        }

        // integer validation
        if (!(cin >> guess)) {
            cout << "Invalid input! Please enter a NUMBER.\n" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cin.ignore(100, '\n');   // throw away leftovers such as ".1"

        // range validation
        if (guess < 1 || guess > 100) {
            cout << "Hey! I said between 1 and 100! This guess doesn't count.\n" << endl;
            continue;
        }

        tries++;

        if (guess > target) {
            if (guess - target <= 5) {
                int i = pickNoRepeat(nearTooHighPhrases.size(), lastNearHighIdx);
                cout << nearTooHighPhrases.at(i) << "\n" << endl;
            } else {
                int i = pickNoRepeat(tooHighPhrases.size(), lastHighIdx);
                cout << tooHighPhrases.at(i) << "\n" << endl;
            }
        }
        else if (guess < target) {
            if (target - guess <= 5) {
                int i = pickNoRepeat(nearTooLowPhrases.size(), lastNearLowIdx);
                cout << nearTooLowPhrases.at(i) << "\n" << endl;
            } else {
                int i = pickNoRepeat(tooLowPhrases.size(), lastLowIdx);
                cout << tooLowPhrases.at(i) << "\n" << endl;
            }
        }
        else if (guess == target && tries <= 4) {
            cout << "Omg you can read my mind!" << "\n" << endl;
        }
        else if (guess == target && tries > 4) {
            cout << averagePhrases.at(rand() % averagePhrases.size()) << endl;
            cout << "You cracked the code in " << tries << " tries. " << endl;
        }

    } while (guess != target);

}
