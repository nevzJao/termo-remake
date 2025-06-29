#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <map>
#include <string>

enum class Color {
    GREEN,
    YELLOW,
    GRAY
};

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

