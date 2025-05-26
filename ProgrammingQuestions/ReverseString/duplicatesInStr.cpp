#include <iostream>
#include <string>
#include <vector>

bool checkRepeat(char c, const std::vector<char>& ref) {
    for (char ch : ref) {
        if (ch == c) {
            return true;  // If character exists, return true
        }
    }
    return false;
}

int main() {
    std::string refStr = "Monnnon";  // Using std::string instead of C-style string
    std::vector<char> cDuplChar;  // Using std::vector for dynamic storage

    // Find duplicate characters
    for (size_t i = 0; i < refStr.length(); i++) {
        for (size_t j = i + 1; j < refStr.length(); j++) {
            if (refStr[j] == refStr[i]) {
                if (!checkRepeat(refStr[i], cDuplChar)) {
                    cDuplChar.push_back(refStr[i]);  // Store duplicate
                }
                break;
            }
        }
    }

    // Print duplicate characters
    std::cout << "Duplicate characters: ";
    for (char ch : cDuplChar) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    return 0;
}