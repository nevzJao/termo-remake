#include "../include/Hud.h"
#include <iostream>
#include <cstdlib>

HUD::HUD() : palavraCorreta("") {}

void HUD::adicionarTentativa(const std::string& tentativa, const std::vector<FeedbackCor>& feedback) {
    tentativas.push_back({tentativa, feedback});
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
            if (keyboard.getKeyColor(letra) != Color::GREEN && 
                keyboard.getKeyColor(letra) != Color::YELLOW) {
                keyboard.setKeyColor(letra, Color::GRAY);
            }
        }
    }
}

void HUD::imprimirHUD() const {
    limparTerminal();

    // Cabeçalho simplificado
    std::cout << "+------------------+" << std::endl;
    std::cout << "|    | Termo  |    |" << std::endl;
    std::cout << "+------------------+" << std::endl;

    // Tentativas
    for (size_t i = 0; i < 6; ++i) {
    std::cout << (i+1) << "ª tentativa: ";
    if (i < tentativas.size()) {
        const auto& [palavra, cores] = tentativas[i];
        for (size_t j = 0; j < palavra.size(); ++j) {
            char letra = palavra[j];
            switch (cores[j]) {
                case FeedbackCor::VERDE:
                    std::cout << "\033[1;32m" << letra << "\033[0m"; break; // verde
                case FeedbackCor::AMARELO:
                    std::cout << "\033[1;33m" << letra << "\033[0m"; break; // amarelo
                case FeedbackCor::CINZA:
                    std::cout << "\033[1;90m" << letra << "\033[0m"; break; // cinza
            }
        }
        std::cout << "\n";
    } else {
        std::cout << "\n";
    }
}

void HUD::limparTerminal() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
