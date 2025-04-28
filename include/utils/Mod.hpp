#pragma once

#include <iostream>
#include <vector>
#include <cstdint>

struct Mod {

    std::string modName;
    std::string author;
    std::string modIdentifier;
    uint8_t modPriority;
    std::string modDescription;

};

class ModManager {
private:
    std::vector<Mod> loadedMods;    
public:
    ModManager();
    ModManager(Mod mod);

    Mod createMod(std::string& name, std::string& author, std::string& description, std::string& modIdentifier);
    void assignPriority();

    std::vector<Mod> getMods();
    void addMod();
    void removeMod();
};