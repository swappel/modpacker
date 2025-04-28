#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "nlohmann/json.hpp"
#include "ConfigurationManager.hpp"

using json = nlohmann::json;

std::unordered_map<std::string, std::string> loadKeyValueConfig(const std::string& filename) {

    std::unordered_map<std::string, std::string> config;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find('=');

        if (delimiterPos == std::string::npos) continue;
        
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);
        
        config[key] = value;
    }
    return config;
}

std::vector<std::string> loadListConfig(const std::string& filename) {
    std::vector<std::string> list;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            list.push_back(line);
        }
    }
    return list;
}

std::vector<std::string> loadListConfigJson(const std::string& filename) {
    std::ifstream file(filename);
    json j;
    file >> j;
    return j["items"].get<std::vector<std::string>>();
}

std::vector<std::string> configNames = {"paths.cfg", "settings.cfg", "mods.json"};

bool createConfigFiles() {

    for (const auto& fileName : configNames) {
        std::ifstream infile("configs/" + fileName);
        if (infile.good()) {
            std::cout << "[AFoP-ModManager] [INFO]" << fileName << " already exists. Skipping creation!";
            continue;
        }
        
        std::ofstream outfile("configs/" + fileName);
        if (!outfile.is_open()) {
            std::cerr << "[AFoP-ModManager] [ERROR] The file configs/" << fileName << " could not be created!";
            return false;
        }
        
        outfile.close();
    }
    
    return true;
}

void init_configurations() {

}