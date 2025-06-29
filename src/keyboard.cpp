#include "../include/Keyboard.h"
#include <iostream>
#include <cctype>

Keyboard::Keyboard() {
    for (char c = 'A'; c <= 'Z'; c++) {
        keyColors[c] = Color::GRAY;
    }
}

void Keyboard::setKeyColor(char letter, Color color) {
    letter = toupper(letter);
    if (letter >= 'A' && letter <= 'Z') {
        keyColors[letter] = color;
    }
}

Color Keyboard::getKeyColor(char letter) const {
    letter = toupper(letter);
    if (keyColors.find(letter) != keyColors.end()) {
        return keyColors.at(letter);
    }
    return Color::GRAY;
}

void Keyboard::printKeyboard() const {
    std::string firstRow = "QWERTYUIOP";
    std::string secondRow = "ASDFGHJKL";
    std::string thirdRow = "ZXCVBNM";

    auto printRow = [this](const std::string& row) {
        for (char c : row) {
            Color color = getKeyColor(c);
            switch (color) {
                case Color::GREEN:
                    std::cout << "\033[42m";
                    break;
                case Color::YELLOW:
                    std::cout << "\033[43m";
                    break;
                case Color::GRAY:
                    std::cout << "\033[47m";
                    break;
            }
            std::cout << " " << c << " \033[0m";
        }
        std::cout << std::endl;
    };

    printRow(firstRow);
    printRow(secondRow);
    printRow(thirdRow);
}

void Keyboard::resetKeyboard() {
    for (auto& pair : keyColors) {
        pair.second = Color::GRAY;
    }
}
