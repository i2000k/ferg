#include "file_organizer.hpp"
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <unordered_set>


void FileOrganizer::create_extension_directories() const {
    // create extension directories
    for(const auto& extension : extensions) {
        if (!std::filesystem::exists(this->base_path / extension)) {
            std::filesystem::create_directory(this->base_path / extension);
        }
    }
}

void FileOrganizer::get_extensions() {
    // get file extensions
    for(const auto& entry : std::filesystem::directory_iterator(base_path)) {
        // working with files only
        if (entry.is_regular_file()) {
            std::string ext = entry.path().extension().string().substr(1); // exclude dot
            std::transform(ext.begin(), ext.end(), ext.begin(), [](unsigned char c)
                { return std::tolower(c); }); // lower uppercase
            this->extensions.emplace(ext);
        }
    }
}

void FileOrganizer::move_files_to_ext_dirs() const {
    for (const auto& entry : std::filesystem::directory_iterator(base_path)) {
        if (entry.is_regular_file()) {
            std::string ext = entry.path().extension().string().substr(1);
            std::filesystem::rename(entry.path(), entry.path().parent_path() / ext / entry.path().filename());
        }
    }
}

void FileOrganizer::clear_extensions() {
    this->extensions.clear();
}

void FileOrganizer::sort_files() {
    get_extensions();
    if (!extensions.empty()) {
        create_extension_directories();
        move_files_to_ext_dirs();
        clear_extensions();
    }
}
