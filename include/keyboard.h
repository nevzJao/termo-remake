#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Color.h"  // Inclua o novo arquivo
#include <map>
#include <string>

class Keyboard {
private:
    std::map<char, Color> keyColors;

public:
    Keyboard();
    void setKeyColor(char letter, Color color);
    Color getKeyColor(char letter) const;
    void printKeyboard() const;
    void resetKeyboard();
};

#endif // KEYBOARD_H