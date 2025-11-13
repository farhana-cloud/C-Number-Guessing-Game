#include <iostream>
#include <random> // For modern C++ random number generation
#include <limits> // For std::numeric_limits

int main() {
    // Use a random_device to seed the random number engine.
    // This provides a non-deterministic source of randomness if available.
    std::random_device rd;

    // Use the Mersenne Twister engine, a high-quality random number generator
    std::mt19937 gen(rd());

    // Define the range for the random number (e.g., 1 to 100)
    std::uniform_int_distribution<> distrib(1, 100);

    // Generate the secret number
    int number = distrib(gen);
    int guess;

    std::cout << "--- Number Guessing Game ---" << std::endl;
    std::cout << "I have selected a secret number between 1 and 100." << std::endl;
    std::cout << "Try to guess it!" << std::endl;

    do {
        std::cout << "\nEnter your guess: ";
        std::cin >> guess;

        // Input validation: Check if the input operation failed (e.g., user entered text)
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Discard the rest of the line to prevent an infinite loop
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Skip the rest of this loop iteration and ask for input again
        }

        if (guess > number) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < number) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "\nCongratulations! You guessed the number: " << number << std::endl;
        }
    } while (guess != number);

    return 0;
}
