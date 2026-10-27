#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Generate a random number between 1 and 100
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "===== NUMBER GUESSING GAME =====" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess the number!" << endl;

    do {
        cout << "\nEnter your guess: ";
        cin >> guess;

        attempts++;

        if (guess < 1 || guess > 100) {
            cout << "Please enter a number between 1 and 100." << endl;
        }
        else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed correctly!"
                 << endl;
            cout << "Number of attempts: " << attempts << endl;
        }

    } while (guess != secretNumber);

    return 0;
}