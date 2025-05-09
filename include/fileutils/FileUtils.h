#pragma once
#include <vector>
#include <string>
#include "../formats/ModArchive.h"

std::vector<FileEntry> collectFiles(const std::string& rootFolder);
void createModSkeleton(const std::string& modPath);