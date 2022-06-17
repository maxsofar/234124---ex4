#include "Merchant.h"
#include <iostream>
#include <string>

using std::cin;
using std::string;

static CardStats getStats()
{
    CardStats merchantStats(0, 0, 0, 10);
    return  merchantStats;
}

Merchant::Merchant() : Card(getStats(), "Merchant")
{}

void Merchant::applyEncounter(Player &player)
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    string input;
    int intInput;
    while(true) {
        getline(cin, input);
        if (cin.fail() || cin.eof() || input.find_first_not_of("012") != string::npos) {
            printInvalidInput();
        } else {
            intInput = std::stoi(input);
            break;
        }
    }
    switch (intInput) {
        case 0:
        {
            printMerchantSummary(std::cout, player.getName(), 0, 0);
        }
            break;

        case 1:
        {
            if (player.pay(5)) {
                player.heal(1);
                printMerchantSummary(std::cout, player.getName(), 1, 5);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
            }
        }
            break;

        case 2:
        {
            if (player.pay(10)) {
                player.buff(1);
                printMerchantSummary(std::cout, player.getName(), 2, 10);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
            }
        }
            break;
    }
}