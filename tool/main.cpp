#include "Mtmchkin.h"

int main() {
    try{
        Mtmchkin game("../deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < 100){
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(const DeckFileInvalidSize& error){
        std::cout << error.what()  << std::endl;
    }
    catch(const DeckFileNotFound& error){
        std::cout << error.what()  << std::endl;
    }
    catch(const DeckFileFormatError& error){
        std::cout << error.what()  << std::endl;
    }
    return 0;
}
