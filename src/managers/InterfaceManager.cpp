#include "InterfaceManager.hpp"
#include <iostream>

std::string gamePathInput;

void startIntroduction() {
    
    std::cout << "Welcome to the utility program for the A:FoP Mod Manager!\n";
    std::cout << "Let's set up the whole thing so everything works!\n";
    std::cout << "First, we need to find the game's main directory, where we will place the modded files for you.\n";
    std::cout << "To find this directory, you'll need to go to your game service(Steam, Epic Games, etc...) and from there, you'll either right click your game or click the three little dots next to it.\n";
    std::cout << "After that, here is what you search for:\n    - If you have your game on steam:\nThen you go to ENTER THINGY HERE.\n\n";
    std::cout << "    - If you have your game on EpicGames, you'll want to go to FILL IN HERE.\n\n";
    std::cout << "    - If you have your game in the Ubisoft Game Launcher, you'll want to FILL IN HERE\n";

    std::cout << "Alright. Now it's your turn! Please paste the path to the main games folder, containing afop.exe here: ";
    std::cin >> gamePathInput;
}

void helpCommand() {

}

void editPaths() {

}