#include <iostream>
#include <io.h>
#include <filesystem>

#include "file_organizer.hpp"

int main(const int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string dir_path = argv[1];
    if (dir_path.empty() || !std::filesystem::exists(dir_path)) {
        std::cerr << "Directory " << dir_path << " does not exist" << std::endl;
        return EXIT_FAILURE;
    }
    FileOrganizer fs(dir_path);

    fs.sort_files();

    return EXIT_SUCCESS;
}
