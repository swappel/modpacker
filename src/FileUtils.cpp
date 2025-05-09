#include "fileutils/FileUtils.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

bool confirmChoice(const std::string& action) {
    std::string userConfirmation;

    std::cout << "Are you sure you want to " << action << "? [Y/n] ";
    getline(std::cin, userConfirmation);
    std::cout << "\n";

    while (userConfirmation != "Y" && userConfirmation != "n") {
        std::cerr << "Invalid input! Y or n: ";
        getline(std::cin, userConfirmation);
        std::cout << "\n";
    }

    return userConfirmation == "Y";
}

std::vector<FileEntry> collectFiles(const std::string& rootFolder) {
    std::vector<FileEntry> files;
    std::cout << "Collecting files...\n";

    for (auto& entry : fs::recursive_directory_iterator(rootFolder)) {
        if (!entry.is_regular_file()) continue;

        FileEntry file;
        file.path = fs::relative(entry.path(), rootFolder).generic_string();
        file.size = fs::file_size(entry.path());
        files.push_back(file);
    }

    std::cout << files.size() << " files collected!\n";

    return files;
}

void createModSkeleton(const std::string &modDirectory) {

    fs::path modPath = modDirectory;

    if (fs::exists(modPath / "blue")) {
        if (confirmChoice("overwrite the \"blue/\" directory")) {
            fs::remove_all(modPath / "blue");
            fs::create_directory(modPath / "blue");
        } else {
            std::cout << "Skipping directory overwrite.\n";
        }
    }
    

    if (fs::exists(modPath / "mod.json")) {
        std::cerr << "mod.json already exists for this mod. ";
        
        if (!confirmChoice("overwrite it")) {
            std::cout << "Operation canceled.\n";
        }
    }
    
    std::string userInput;

    std::ofstream out(modPath / "mod.json");

    if (!out) {
        std::cerr << "Couldn't access the mod.json file. Canceling.\n";
        return;
    }

    out << "{\n";

    std::cout << "Alright, let's start!\n"
              << "What should be your mod's name: ";

    getline(std::cin, userInput);

    // Prompt the mod name
    bool confirmed = confirmChoice("choose " + userInput + " as the mod name");

    while (!confirmed) {
        std::cout << "Enter a new mod name: ";
        getline(std::cin, userInput);
        std::cout << "\n";
        confirmed = confirmChoice("choose " + userInput + " as the mod name");
    }
    
    out << "    \"name\": \""<< userInput << "\",\n";
    std::cout << "Set " << userInput << " as the mod name.\n";

    // Prompt the Mod ID
    std::cout << "Please choose your Mod ID (this needs to be as unique as possible; A mod with the same Mod ID will cause an error) [Format: MOD_NAME]: ";
    getline(std::cin, userInput);

    confirmed = confirmChoice("choose " + userInput + " as the Mod ID");

    while (!confirmed) {
        std::cout << "Enter a new Mod ID: ";
        getline(std::cin, userInput);
        std::cout << "\n";
        confirmed = confirmChoice("choose " + userInput + " as the Mod ID");
    }

    out << "    \"id\": \""<< userInput << "\",\n";
    std::cout << "Set " << userInput << " as the Mod ID.\n";

    // Prompt the Mod Author
    std::cout << "Please enter the author's name: ";
    getline(std::cin, userInput);

    confirmed = confirmChoice("choose " + userInput + " as the author's name");

    while (!confirmed) {
        std::cout << "Enter a new author name: ";
        getline(std::cin, userInput);
        std::cout << "\n";
        confirmed = confirmChoice("choose " + userInput + " as the author's name");
    }

    out << "    \"author\": \""<< userInput << "\",\n";
    std::cout << "Set " << userInput << " as the author name.\n";

    // Prompt the mod version
    std::cout << "Please enter the mod's version: ";
    getline(std::cin, userInput);

    confirmed = confirmChoice("choose " + userInput + " as the mod's version");

    while (!confirmed) {
        std::cout << "Enter a new mod version: ";
        getline(std::cin, userInput);
        std::cout << "\n";
        confirmed = confirmChoice("choose " + userInput + " as the mod's version");
    }

    out << "    \"version\": \""<< userInput << "\",\n";
    std::cout << "Set " << userInput << " as the mod version.\n";

    // Prompt the mod description
    std::cout << "Please enter the mod's description: ";
    getline(std::cin, userInput);

    confirmed = confirmChoice("choose " + userInput + " as the mod description");

    while (!confirmed) {
        std::cout << "Enter a new mod description: ";
        getline(std::cin, userInput);
        std::cout << "\n";
        confirmed = confirmChoice("choose " + userInput + " as the mod's description");
    }
    
    out << "    \"description\": \""<< userInput << "\"\n";
    std::cout << "Set " << userInput << " as the mod description.\n";

    out << "}";

    out.close();
}