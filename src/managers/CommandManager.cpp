#include <string>
#include "managers/CommandManager.hpp"
#include "managers/InterfaceManager.hpp"

void analyzeInput(std::string &userInput) {
    if (userInput == "help") {
        helpCommand();
    }
    
}