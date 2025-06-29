#include "../include/PalavraUser.h"
#include <algorithm>

PalavraUser::PalavraUser(const std::string& tentativa, const std::string& palavraSecreta) {
    palavra = tentativa;
    cores.resize(palavra.size(), Color::BLACK);  // Changed from GRAY to BLACK

    std::vector<bool> usada(palavraSecreta.size(), false);

    // First pass: mark correct letters (GREEN)
    for (size_t i = 0; i < palavra.size(); i++) {
        if (i < palavraSecreta.size() && palavra[i] == palavraSecreta[i]) {
            cores[i] = Color::GREEN;
            usada[i] = true;
        }
    }

    // Second pass: mark present but wrong position letters (YELLOW)
    for (size_t i = 0; i < palavra.size(); i++) {
        if (cores[i] == Color::GREEN) continue;
        
        for (size_t j = 0; j < palavraSecreta.size(); j++) {
            if (!usada[j] && palavra[i] == palavraSecreta[j]) {
                cores[i] = Color::YELLOW;
                usada[j] = true;
                break;
            }
        }
    }
}

std::string PalavraUser::getPalavra() const {
    return palavra;
}

Color PalavraUser::getColor(size_t index) const {
    return cores.at(index); // Usando at() para verificação de limites
}

size_t PalavraUser::size() const {
    return palavra.size();
}