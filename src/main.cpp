#include "fileutils/FileUtils.h"
#include "packer/Packer.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage:\n";
        std::cout << "  modpacker pack <input_folder> <output_file>\n";
        std::cout << "  modpacker unpack <input_file> <output_folder>\n";
        std::cout << "  modpacker info <input_file>\n";
        return 1;
    }

    std::string command = argv[1];

    try {
        if (command == "pack" && argc == 4) {
            pack(argv[2], argv[3]);
        } else if (command == "unpack" && argc == 4) {
            unpack(argv[2], argv[3]);
        } else if (command == "info" && argc == 3) {
            showInfo(argv[2]);
        } else if (command == "init_mod" && argc == 3) {
            createModSkeleton(argv[2]);
        } else {
            std::cerr << "Invalid command or arguments.\n";
            return 1;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
