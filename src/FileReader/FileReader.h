// FileReader.h
#include <string>
#include <vector>
#include <fstream>

class FileReader {
public:
    FileReader(const std::string& filePath);
    bool IsOpen() const;
    bool ReadLine(std::string& line);
    void Close();

private:
    std::string filePath;
    std::ifstream file;
};

