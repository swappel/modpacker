#pragma once
#include <string>

void pack(const std::string& inputFolder, const std::string& outputFile);
void unpack(const std::string& inputFile, const std::string& outputFolder);
void showInfo(const std::string& inputFile);