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
    std::vector<int> top3Calories;

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            // An empty line indicates the end of an Elf's inventory.
            top3Calories.push_back(currentCalories);
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
    top3Calories.push_back(currentCalories);

    if (!top3Calories.empty()) {
        // Sort the top3Calories vector in descending order.
        std::sort(top3Calories.rbegin(), top3Calories.rend());

        // Calculate the total calories carried by the top three Elves.
        int totalTop3Calories = 0;
        for (int i = 0; i < 3 && i < top3Calories.size(); ++i) {
            totalTop3Calories += top3Calories[i];
        }

        std::cout << "Total calories carried by the top three Elves: " << totalTop3Calories << std::endl;
    } else {
        std::cout << "No calorie information found." << std::endl;
    }

    return 0;
}