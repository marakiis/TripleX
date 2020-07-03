#include <iostream>
#include <string>
#include <time.h>

int Pick(int max) {
    return (std::rand() % max) + 1; // Pick a number between 1 and max
}

void Introduction() {
    // Welcome player
    std::cout << "You're a secret agent breaking into a secret server room...\n";
    std::cout << "It seems the room is protected by a security lock...\n";
    // Initialize rand
    srand(time(NULL));
}

int Win(int Level) {
    std::cout << "You guessed the code. Well done !\n";
    if (Level < 10) {
        std::cout << "Oh no! another lock!\n";
    } else {
        std::cout << "The server is here. Quick get what you need and leave!\n";
        return 0;
    }
    return Level + 1;
}

void Loose() {
    std::cout << "You failed ! Sorry but I have to kill you.\n";
}

bool GameLoop(int Level) {
    std::cout << "This is a level " << Level << " security lock.\n";
    
    // Create 3 number code
    const int CodeA = Pick(Level);
    const int CodeB = Pick(Level);
    const int CodeC = Pick(Level);
    // Compute code helper
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print code helper
    std::cout << "There are 3 numbers in the code.\n";
    std::cout << "The numbers sum is " << CodeSum << std::endl;
    std::cout << "The numbers product is " << CodeProduct << std::endl;
    std::cout << "Can you guess the code...\n";

    // Get player input
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << ", " << GuessB << ", " << GuessC << std::endl;

    // Process player input
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Compare player guess to the code
    return (GuessSum == CodeSum && GuessProduct == CodeProduct);
}


int main() {
    Introduction();
    
    int Level = 5;
    bool bPlaying = true; 

    while (bPlaying) {
        if (GameLoop(Level)) {
            Level = Win(Level);
            if (Level == 0) {
                bPlaying =  false;
            }
        } else {
            Loose();
            bPlaying = false;
        }
        // Discard any remaining buffer
        std::cin.clear();
        std::cin.ignore();
    }
    return 0;
}
