#ifndef HUD_H
#define HUD_H

#include "keyboard.h"
#include "palavraUser.h"
#include <vector>
#include <string>

class HUD {
private:
    std::vector<std::pair<std::string, std::vector<FeedbackCor>>> tentativas;
    std::string palavraCorreta;
    Keyboard keyboard;

public:
    HUD();

    // Adiciona uma tentativa ao HUD
    void adicionarTentativa(const std::string& tentativa);

    // Define a palavra correta (para quando o jogador perde)
    void setPalavraCorreta(const std::string& palavra);

    // Atualiza as cores do teclado com base nas tentativas
    void atualizarTeclado(const std::string& tentativa, const std::string& palavraSecreta);

    // Limpa o terminal e imprime todo o HUD
    void imprimirHUD() const;

    // Limpa o terminal
    void limparTerminal() const;
};

#endif // HUD_H 
