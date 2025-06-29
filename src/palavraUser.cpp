#include "../include/PalavraUser.h"
#include <algorithm>
#include <map>

PalavraUser::PalavraUser(const std::string& tentativa) {
    palavra = tentativa;
    std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::toupper);
}

bool PalavraUser::ehValida() const {
    return palavra.size() == 5;
}

std::string PalavraUser::getPalavra() const {
    return palavra;
}

std::vector<FeedbackCor> PalavraUser::compararCom(const std::string& palavraSecreta) const {
    std::vector<FeedbackCor> resultado(5, FeedbackCor::CINZA);
    std::string secreta = palavraSecreta;
    std::vector<bool> usada(5, false);

    for (int i = 0; i < 5; ++i) {
        if (palavra[i] == secreta[i]) {
            resultado[i] = FeedbackCor::VERDE;
            usada[i] = true;
        }
    }

    for (int i = 0; i < 5; ++i) {
        if (resultado[i] == FeedbackCor::VERDE) continue;
        for (int j = 0; j < 5; ++j) {
            if (!usada[j] && palavra[i] == secreta[j]) {
                resultado[i] = FeedbackCor::AMARELO;
                usada[j] = true;
                break;
            }
        }
    }

    return resultado;
}
