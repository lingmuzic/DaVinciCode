// Da Vinci Code - number guessing game (console)
// Pick a version from the menu to play it.

#include <iostream>
#include "games.h"

using namespace std;

int main() {
    int choice{ 0 };

    do {
        cout << "--- Da Vinci Code: Version Menu ---" << endl;
        cout << "1. Version 1 (core logic)" << endl;
        cout << "2. Version 2 (input validation, random phrases)" << endl;
        cout << "3. Version 3 (near-miss hints, no repeats)" << endl;
        cout << "0. Exit" << endl;
        cout << "Select: ";

        if (!(cin >> choice)) {
            cout << "Invalid selection. Please enter a number.\n" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cin.ignore(100, '\n');

        switch (choice) {
        case 1: run_v1(); break;
        case 2: run_v2(); break;
        case 3: run_v3(); break;
        case 0: cout << "Goodbye!" << endl; break;
        default: cout << "Version not found." << endl;
        }

        cout << "\n-------------------------------------\n" << endl;

    } while (choice != 0);

    return 0;
}
