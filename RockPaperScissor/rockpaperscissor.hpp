#ifndef ROCKPAPERSCISSOR_HPP
#define ROCKPAPERSCISSOR_HPP

#include <string>

class RockPaperScissor {
public:
    RockPaperScissor();
    // Run the main game loop
    void run();

private:
    int choices[3];
    std::string names[3];

    // Get the user's choice (1..3)
    int getUserChoice();
    // Get the computer's choice (0..2)
    int getComputerChoice();
    // Determine winner: returns 1 if user wins, 0 if user loses, -1 if tie
    int determineWinner(int userChoiceIndex, int computerChoiceIndex);
    // Clear the terminal screen (best-effort)
    void clearScreen();
};

#endif // ROCKPAPERSCISSOR_HPP
