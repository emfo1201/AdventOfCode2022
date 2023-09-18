#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

int main() {
    std::cout << "Hello!" << std::endl;
    std::vector<int> calorieData;  // A vector to store calorie information.

    // Specify the file path you want to read.
    std::string filepath = "C:/Users/rissl/Desktop/AdventOfCode2022/data/day01.txt"; // Replace "your_file.txt" with the actual file name.

    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filepath << std::endl;
        return 1;
    }

    int currentCalories = 0;
    int maxCalories = 0;

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            // An empty line indicates the end of an Elf's inventory.
            maxCalories = std::max(maxCalories, currentCalories);
            currentCalories = 0;
        } else {
            try {
                int calorie = std::stoi(line);
                calorieData.push_back(calorie);
                currentCalories += calorie;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Failed to parse line: " << line << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Value out of range in line: " << line << std::endl;
            }
        }
    }

    file.close();

    // Check the last Elf's inventory.
    maxCalories = std::max(maxCalories, currentCalories);

    if (maxCalories > 0) {
        std::cout << "The Elf carrying the most calories has a total of " << maxCalories << " calories." << std::endl;
    } else {
        std::cout << "No calorie information found." << std::endl;
    }

    return 0;
}