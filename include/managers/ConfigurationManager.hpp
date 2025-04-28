#pragma once 

#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, std::string> loadKeyValueConfig(const std::string& filename);
std::vector<std::string> loadListConfig(const std::string& filename);
std::vector<std::string> loadListConfigJson(const std::string& filename);

bool createConfigFiles();

void init_configurations();