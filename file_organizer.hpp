#ifndef FILE_SORTER_HPP
#define FILE_SORTER_HPP
#include <filesystem>
#include <string>
#include <unordered_set>


class FileOrganizer {
    std::filesystem::path base_path;
    std::unordered_set<std::string> extensions;
    void create_extension_directories() const;
    void get_extensions();
    void move_files_to_ext_dirs() const;
    void clear_extensions();
public:
    explicit FileOrganizer(const std::string& path) : base_path(path) {};
    void sort_files();
};



#endif //FILE_SORTER_HPP
