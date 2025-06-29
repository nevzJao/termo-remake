#ifndef HUB_H
#define HUB_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "keyboard.h"
#include "PalavraSecreta.h"

class Hub : public QWidget {
    Q_OBJECT

public:
    explicit Hub(QWidget *parent = nullptr);

private slots:
    void handleKeyPressed(const QString &key);

private:
    PalavraSecreta jogo;
    Keyboard *keyboard;
    QVBoxLayout *mainLayout;
    QLabel *display;

    QString currentGuess;
    int attempts;

    void checkGuess();
    void resetGame();
};

#endif
