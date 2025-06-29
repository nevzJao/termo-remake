#include "../include/Hud.h"
#include <iostream>
#include <cstdlib>

HUD::HUD() : palavraCorreta("") {}

void HUD::adicionarTentativa(const std::string& tentativa, const std::string& palavraSecreta) {
    tentativas.emplace_back(tentativa, palavraSecreta);
    atualizarTeclado(tentativa, palavraSecreta);
}


void HUD::setPalavraCorreta(const std::string& palavra) {
    palavraCorreta = palavra;
}

void HUD::atualizarTeclado(const std::string& tentativa, const std::string& palavraSecreta) {
    for (size_t i = 0; i < tentativa.size(); ++i) {
        char letra = tentativa[i];
        
        if (letra == palavraSecreta[i]) {
            keyboard.setKeyColor(letra, Color::GREEN);
        } else if (palavraSecreta.find(letra) != std::string::npos) {
            if (keyboard.getKeyColor(letra) != Color::GREEN) {
                keyboard.setKeyColor(letra, Color::YELLOW);
            }
        } else {
            keyboard.setKeyColor(letra, Color::BLACK);
        }
    }
}

void HUD::imprimirHUD() const {
    limparTerminal();

    std::cout << "+------------------+" << std::endl;
    std::cout << "|    | Termo  |    |" << std::endl;
    std::cout << "+------------------+" << std::endl;

    for (size_t i = 0; i < 6; ++i) {
        std::cout << (i+1) << "ª tentativa: ";
        if (i < tentativas.size()) {
            const PalavraUser& tentativa = tentativas[i];
            for (size_t j = 0; j < tentativa.size(); j++) {
                                switch (tentativa.getColor(j)) {
                    case Color::GREEN:
                        std::cout << "\033[42m" << tentativa.getPalavra()[j] << "\033[0m";
                        break;
                    case Color::YELLOW:
                        std::cout << "\033[43m" << tentativa.getPalavra()[j] << "\033[0m";
                        break;
                    case Color::BLACK:
                        std::cout << "\033[40m" << tentativa.getPalavra()[j] << "\033[0m";
                        break;
                    case Color::GRAY:
                    default:
                        std::cout << "\033[47m" << tentativa.getPalavra()[j] << "\033[0m";
                }
            }
        }
        std::cout << std::endl;
    }

    if (!palavraCorreta.empty()) {
        std::cout << "\nNão foi dessa vez 😉\n";
        std::cout << "A palavra era " << palavraCorreta << "\n\n";
    }

    std::cout << "\n";
    keyboard.printKeyboard();
}


void HUD::limparTerminal() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}