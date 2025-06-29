#include "../include/Hub.h"
#include <QMessageBox>
#include <QString>
#include <algorithm>

Hub::Hub(QWidget *parent)
    : QWidget(parent), jogo("data/palavras.txt"), attempts(0) {
    
    keyboard = new Keyboard(this);
    display = new QLabel("Digite a palavra clicando nas letras.\n", this);
    mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(display);
    mainLayout->addWidget(keyboard);

    setLayout(mainLayout);

    connect(keyboard, &Keyboard::keyPressed, this, &Hub::handleKeyPressed);
}

void Hub::handleKeyPressed(const QString &key) {
    currentGuess += key;

    display->setText("Palavra atual: " + currentGuess);

    if (currentGuess.length() == 5) {
        checkGuess();
    }
}

void Hub::checkGuess() {
    QString correct = QString::fromStdString(jogo.getPalavra());

    QString guess = currentGuess.toUpper();
    currentGuess.clear();
    attempts++;

    // Feedback (simple coloring)
    for (int i = 0; i < 5; ++i) {
        QString letra = guess.mid(i, 1);
        if (letra == correct.mid(i, 1)) {
            keyboard->updateKeyColor(letra, "green");
        } else if (correct.contains(letra)) {
            keyboard->updateKeyColor(letra, "yellow");
        } else {
            keyboard->updateKeyColor(letra, "gray");
        }
    }

    if (guess == correct) {
        QMessageBox::information(this, "Vitória!", "Você acertou a palavra!");
        resetGame();
    } else if (attempts >= 6) {
        QMessageBox::information(this, "Fim de jogo", "Você perdeu. A palavra era: " + correct);
        resetGame();
    }
}

void Hub::resetGame() {
    jogo = PalavraSecreta("data/palavras.txt");
    keyboard->resetKeyboard();
    attempts = 0;
    currentGuess.clear();
    display->setText("Digite a palavra clicando nas letras.\n");
}
