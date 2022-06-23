#include "Mtmchkin.h"
#include <string>

int main() {
    std::string input("3\nJonSnow Fighter\nAlbusDumbledore Wizard\nJackSparrow Rogue");
    std::istringstream in(input);
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());

    try{
        Mtmchkin game("../deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < 100){
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(const Exception& error){
        std::cout << error.what()  << std::endl;
    }
    std::cin.rdbuf(cinbuf);

    return 0;
}
