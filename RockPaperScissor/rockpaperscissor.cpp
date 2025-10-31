#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rockpaperscissor.hpp"

using namespace std;

RockPaperScissor::RockPaperScissor() {
    // Seed RNG so computer choice differs across runs
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    choices[0] = 1;
    choices[1] = 2;
    choices[2] = 3;
    names[0] = "Rock";
    names[1] = "Paper";
    names[2] = "Scissor";
}

int RockPaperScissor::getUserChoice() {
    int uc;
    cout<<"Enter 1 for Rock."<<"\n";
    cout<<"Enter 2 for Paper."<<"\n";
    cout<<"Enter 3 for Scissor."<<"\n";
    cout<<"Enter your choice:"<<"\n";
    if(!(cin>>uc)) {
        // invalid input, clear and return -1
        cin.clear();
        string dummy;
        getline(cin, dummy);
        return -1;
    }
    if(uc < 1 || uc > 3) return -1;
    return uc;
}

int RockPaperScissor::getComputerChoice() {
    return (rand() % 3); // returns 0..2
}

int RockPaperScissor::determineWinner(int userChoiceIndex, int computerChoiceIndex) {
    // Convert userChoiceIndex (1..3) to 0-based
    int u = userChoiceIndex - 1;
    int c = computerChoiceIndex;
    if(u == c) return -1; // tie

    // rock(0) beats scissor(2)
    if(u == 0 && c == 2) return 1;
    if(u == 1 && c == 0) return 1; // paper beats rock
    if(u == 2 && c == 1) return 1; // scissor beats paper

    return 0; // user loses
}

void RockPaperScissor::clearScreen() {
    // Best-effort clear screen for many terminals
    cout << "\e[1;1H\e[2J";
}

void RockPaperScissor::run() {
    int w;
    int uc, cc, c;
    while(true) {
        uc = getUserChoice();
        if(uc == -1) {
            cout<<"Invalid choice. Session being terminated..."<<"\n";
            return;
        }

        cc = getComputerChoice();

        cout<<"You chose: "<<names[uc-1]<<"\n";
        cout<<"Computer chose: "<<names[cc]<<"\n";

        w = determineWinner(uc, cc);

        if(w == 1) {
            cout<<"You won!"<<"\n";
        }
        else if(w == 0) {
            cout<<"You lose!"<<"\n";
        }
        else {
            cout<<"Tie!"<<"\n";
        }

        cout<<"Do you want to play again?"<<"\n";
        cout<<"Enter 1 for YES."<<"\n";
        cout<<"Enter 2 for NO."<<"\n";
        if(!(cin>>c)) {
            cout<<"Invalid input. Session being terminated..."<<"\n";
            return;
        }

        if(c == 2) {
            cout<<"Session being terminated..."<<"\n";
            return;
        }
        else if(c != 1) {
            cout<<"Wrong choice! Session being terminated..."<<"\n";
            return;
        }
        else {
            clearScreen();
            cc=0;
            uc=0;
        }
    }
}
