#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGame() {
    srand(time(0));
    int a = rand() % 10 + 1;
    int b, i;
    int t = 0;

    cout << "NUMBER GUESSING GAME" << endl;
    cout << "The number is between 0 to 10" << endl << "Now start guessing" << endl;

    for (i = 0; i < 10; i++) {
        cout << "Guess " << i + 1 << ": ";
        cin >> b;
        if (a == b) {
            cout << "Your guess is right" << endl;
            t = 1;
            break;
        }
        else if (a > b) {
            cout << "Your Guess is smaller than the number itself" << endl;
        }
        else if (a < b) {
            cout << "Your Guess is larger than the number itself" << endl;
        }
    }

    if (t == 0) {
        cout << "The number was " << a << endl << "You were unable to guess it. :(" << endl;
    }
    else if (t == 1) {
        cout << "You were able to guess the number within given number of tries" << endl << "Your Score: " << (10 - i) * 10 << "/100" << endl;
    }
}

int main() {
    char choice;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    cout << "Thank you for playing! :)" << endl;
    return 0;
}
