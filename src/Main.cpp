#include "managers/InterfaceManager.hpp"
#include "managers/CommandManager.hpp"
#include <iostream>

int main() {

    std::cout << "[AFoP-ModManager] [INFO] Welcome to the AFoP-ModManager! Type help for a list of commands!";

    startIntroduction();

    std::string userInput;

    while (true) {
        std::cout << "> ";
        std::cin >> userInput;

        analyzeInput(userInput);
        
    }
    

    return 0;
}