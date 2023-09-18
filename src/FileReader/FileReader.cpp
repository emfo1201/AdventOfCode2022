// FileReader.cpp
#include "FileReader.h"
#include <iostream>

FileReader::FileReader(const std::string& filePath) : filePath(filePath) {
    file.open(filePath);
}

bool FileReader::IsOpen() const {
    return file.is_open();
}

bool FileReader::ReadLine(std::string& line) {
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return false;
    }

    if (std::getline(file, line)) {
        return true;
    }

    return false;
}

void FileReader::Close() {
    if (file.is_open()) {
        file.close();
    }
}
