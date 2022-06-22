#include "Merchant.h"
#include <iostream>
#include <string>

#define AVAILABLE_CHOICES "012"

using std::cin;
using std::string;

Merchant::Merchant() : Card(CardStats (), "Merchant")
{}

static int getInput()
{
    string input;
    while(true) {
        getline(cin, input);
        if (cin.fail() || cin.eof() || input.empty() || input.find_first_not_of(AVAILABLE_CHOICES) != string::npos) {
            printInvalidInput();
        } else {
            return std::stoi(input);
        }
    }
}

void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int input = getInput();
    switch (input) {
        case 0:
        {
            printMerchantSummary(std::cout, player.getName(), input, 0);
        }
            break;

        case 1:
        {
            if (player.pay(HP_BUFF_COST)) {
                player.heal(HP_BUFF_AMOUNT);
                printMerchantSummary(std::cout, player.getName(), input, HP_BUFF_COST);
            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), input, 0);
            }
        }
            break;

        case 2:
        {
            if (player.pay(FORCE_BUFF_COST)) {
                player.buff(FORCE_BUFF_AMOUNT);
                printMerchantSummary(std::cout, player.getName(), input, FORCE_BUFF_COST);
            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), input, 0);
            }
        }
            break;
    }
}