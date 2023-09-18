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
                {{'A', 'Y'}, 4},  // Y betyder oavgjort, så 1 (din val) + 3 (oavgjort) = 4 poäng.
                {{'A', 'X'}, 3},  // X betyder förlust, så 3 (din val) + 0 (förlust) = 3 poäng.
                {{'A', 'Z'}, 8},  // Z betyder vinst, så 2 (din val) + 6 (vinst) = 8 poäng.
                {{'B', 'Y'}, 5},  // Y betyder oavgjort, så 2 (din val) + 3 (oavgjort) = 5 poäng.
                {{'B', 'X'}, 1},  // X betyder förlust, så 1 (din val) + 0 (förlust) = 1 poäng.
                {{'B', 'Z'}, 9},  // Z betyder vinst, så 3 (din val) + 6 (vinst) = 9 poäng.
                {{'C', 'Y'}, 6},  // Y betyder oavgjort, så 3 (din val) + 3 (oavgjort) = 6 poäng.
                {{'C', 'X'}, 2},  // X betyder förlust, så 2 (din val) + 0 (förlust) = 2 poäng.
                {{'C', 'Z'}, 7}   // Z betyder vinst, så 1 (din val) + 6 (vinst) = 7 poäng.
            };


            totalScore += scores.at({opponentChoice, yourChoice});
        }
    }

    reader.Close(); // Close the FileReader.

    std::cout << "Total score based on the strategy guide: " << totalScore << std::endl;

    return 0;
}