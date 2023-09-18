#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "../FileReader/FileReader.h"

int main() {
    // Specify the path to the file you want to read.
    std::string filepath = "C:/Users/rissl/Desktop/AdventOfCode2022/data/day02.txt"; // Replace with your file path.

    // Use FileReader to open and read the file.
    FileReader reader(filepath);

    if (!reader.IsOpen()) {
        std::cerr << "Failed to open the file: " << filepath << std::endl;
        return 1;
    }

    int totalScore = 0;
    std::string line;

    while (reader.ReadLine(line)) {
        if (line.size() >= 3) {
            char opponentChoice = line[0];
            char yourChoice = line[2];

            // Map the different combinations and scores they produces.
            const std::map<std::pair<char, char>, int> scores = {
                {{'A', 'Y'}, 8},
                {{'A', 'X'}, 4},
                {{'A', 'Z'}, 3},
                {{'B', 'Y'}, 5},
                {{'B', 'X'}, 1},
                {{'B', 'Z'}, 9},
                {{'C', 'Y'}, 2},
                {{'C', 'X'}, 7},
                {{'C', 'Z'}, 6}
            };

            totalScore += scores.at({opponentChoice, yourChoice});
        }
    }

    reader.Close(); // Close the FileReader.

    std::cout << "Total score based on the strategy guide: " << totalScore << std::endl;

    return 0;
}