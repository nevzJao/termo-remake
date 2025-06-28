#include "keyboard.h"

Keyboard::Keyboard(QWidget *parent) : QWidget(parent) {
    layout = new QGridLayout(this);
    setupKeys();
}

void Keyboard::setupKeys() {
    QString keys = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int row = 0;
    int col = 0;

    for (int i = 0; i < keys.length(); i++) {
        QPushButton *btn = new QPushButton(QString(keys[i]), this);
        btn->setFixedSize(40, 40);
        layout->addWidget(btn, row, col);
        buttons.insert(QString(keys[i]), btn);

    
        if (row == 0 && col == 9) {
            row++;
            col = 0;
        }
        else if (row == 1 && col == 8) {
            row++;
            col = 1;
        }
        else {
            col++;
        }

        
        connect(btn, &QPushButton::clicked, [this, btn]() {
            emit keyPressed(btn->text());
        });
    }
}

void Keyboard::updateKeyColor(const QString &key, const QString &color) {
    if (buttons.contains(key)) {
        QString style = QString("background-color: %1").arg(color);
        buttons[key]->setStyleSheet(style);
    }
}

void Keyboard::resetKeyboard() {
    for (auto btn : buttons) {
        btn->setStyleSheet("");
        btn->setEnabled(true);
    }
}
