#ifndef HUD_H
#define HUD_H

#include "PalavraUser.h"
#include "keyboard.h"
#include <vector>
#include <string>

class HUD {
private:
    std::vector<PalavraUser> tentativas;
    std::string palavraCorreta;
    Keyboard keyboard;

public:
    HUD();
    void adicionarTentativa(const std::string& tentativa, const std::string& palavraSecreta);
    void setPalavraCorreta(const std::string& palavra);
    void atualizarTeclado(const std::string& tentativa, const std::string& palavraSecreta);
    void imprimirHUD() const;
    void limparTerminal() const;
};

#endif // HUD_H