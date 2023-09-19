#include <iostream>
#include <string>
#include <unordered_set>
#include "../FileReader/FileReader.h" // Include the custom FileReader class header.

int calculatePriority(char item) {
    if (islower(item)) {
        return item - 'a' + 1;
    } else if (isupper(item)) {
        return item - 'A' + 27;
    } else {
        return 0; // Invalid item type.
    }
}

int main() {
    std::cout << "Hello!" << std::endl;

    // Specify the path to the file you want to read.
    std::string filePath = "C:/Users/rissl/Desktop/AdventOfCode2022/data/day03.txt";

    // Create an instance of the FileReader class and open the file.
    FileReader fileReader(filePath);

    if (!fileReader.IsOpen()) {
        std::cerr << "Failed to open the file: " << filePath << std::endl;
        return 1;
    }

    std::string line;
    int totalPrioritySum = 0;

    // Read the file line by line using the FileReader.
    while (fileReader.ReadLine(line)) {
        int halfSize = line.length() / 2;
        std::unordered_set<char> firstCompartment(line.begin(), line.begin() + halfSize);

        for (int i = halfSize; i < line.length(); i++) {
            char item = line[i];

            // Check if the item type appears in both compartments.
            if (firstCompartment.count(item)) {
                totalPrioritySum += calculatePriority(item);
                firstCompartment.erase(item); // Remove to avoid double counting.
            }
        }
    }

    fileReader.Close(); // Close the FileReader.

    std::cout << "Total sum of priorities: " << totalPrioritySum << std::endl;

    return 0;
}