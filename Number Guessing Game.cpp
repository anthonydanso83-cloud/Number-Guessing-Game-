#include<iostream>
using namespace std;
#include <iostream>
using namespace std;

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Seed the random number generator with current time
    srand(time(0));
    
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    
    int playerGuess;
    int numberOfGuesses = 0;
    bool hasGuessedCorrectly = false;
    
    cout << "🎮 Welcome to the Number Guessing Game! 🎮" << endl;
    cout << "==========================================" << endl;
    cout << "I have selected a secret number between 1 and 100." << endl;
    cout << "Try to guess it! I'll give you hints along the way." << endl;
    cout << "==========================================" << endl;
    
    // Game loop - continues until player guesses correctly
    while (!hasGuessedCorrectly) {
        cout << "\nEnter your guess (1-100): ";
        cin >> playerGuess;
        
        // Input validation
        if (playerGuess < 1 || playerGuess > 100) {
            cout << "⚠️  Please enter a number between 1 and 100." << endl;
            continue;
        }
        
        numberOfGuesses++;
        
        // Check the player's guess
        if (playerGuess == secretNumber) {
            hasGuessedCorrectly = true;
            cout << "\n🎉 Congratulations! You guessed it! 🎉" << endl;
            cout << "The secret number was indeed " << secretNumber << "!" << endl;
            cout << "You found it in " << numberOfGuesses << " guess(es)." << endl;
            
            // Provide feedback based on number of guesses
            if (numberOfGuesses == 1) {
                cout << "Wow! That's incredible luck! 🍀" << endl;
            } else if (numberOfGuesses <= 5) {
                cout << "Excellent guessing skills! 👍" << endl;
            } else if (numberOfGuesses <= 10) {
                cout << "Good job! 👏" << endl;
            } else {
                cout << "You got there in the end! 💪" << endl;
            }
            
        } else if (playerGuess < secretNumber) {
            cout << "📈 Too low! Try a higher number." << endl;
            
            // Additional hint based on how close the guess is
            int difference = secretNumber - playerGuess;
            if (difference > 30) {
                cout << "   (You're way too low!)" << endl;
            } else if (difference > 15) {
                cout << "   (You're quite low)" << endl;
            } else {
                cout << "   (You're getting close!)" << endl;
            }
            
        } else { // playerGuess > secretNumber
            cout << "📉 Too high! Try a lower number." << endl;
            
            // Additional hint based on how close the guess is
            int difference = playerGuess - secretNumber;
            if (difference > 30) {
                cout << "   (You're way too high!)" << endl;
            } else if (difference > 15) {
                cout << "   (You're quite high)" << endl;
            } else {
                cout << "   (You're getting close!)" << endl;
            }
        }
        
        // Display guess count after each attempt
        cout << "Guess #" << numberOfGuesses << endl;
    }
    
    cout << "\n==========================================" << endl;
    cout << "Thanks for playing the Number Guessing Game!" << endl;
    cout << "==========================================" << endl;
    
    return 0;
}