#include <iostream>
#include "utils/Mod.hpp"

ModManager::ModManager() {}

ModManager::ModManager(Mod mod) : loadedMods{mod} {

};

Mod ModManager::createMod(std::string& name, std::string& author, std::string& description, std::string& modIdentifier) {
    Mod mod;
    
    mod.modName = name;
    mod.author = author;
    mod.modDescription = description;
    mod.modIdentifier = modIdentifier;
    mod.modPriority = 0;
    
    for (int i = 0; i < ModManager::loadedMods.size(); i++) {
        if (ModManager::loadedMods[i].modIdentifier == modIdentifier) {
            std::cerr << "[]";
            return {};
        }
    }
    

    ModManager::loadedMods.push_back(mod);

    return mod;
}

