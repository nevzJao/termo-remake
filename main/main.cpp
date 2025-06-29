#include "../include/Hud.h"
#include "../include/PalavraSecreta.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <unistd.h>
#include <limits.h>

// Função para validar a palavra digitada
bool validarPalavra(const std::string& palavra) {
    if (palavra.length() != 5) {
        std::cout << "A palavra deve ter exatamente 5 letras!\n";
        return false;
    }
    
    for (char c : palavra) {
        if (!isalpha(c)) {
            std::cout << "Apenas letras são permitidas!\n";
            return false;
        }
    }
    return true;
}

// Função para converter para maiúsculas e remover acentos
std::string processarPalavra(std::string palavra) {
    std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::toupper);
    // Aqui você pode adicionar a lógica de remover acentos se necessário
    return palavra;
}

int main() {
    // Inicializa o jogo
    PalavraSecreta palavraSecreta("/data/palavras.txt");
    HUD hud;
    std::string palavra = palavraSecreta.getPalavra();
    std::string tentativa;
    int tentativasRestantes = 6;

    std::cout << "=== TERMO ===" << std::endl;
    std::cout << "Digite palavras de 5 letras para adivinhar a palavra secreta.\n\n";

    while (tentativasRestantes > 0) {
        std::cout << "Tentativas restantes: " << tentativasRestantes << std::endl;
        std::cout << "Digite sua tentativa: ";
        std::cin >> tentativa;

        // Processa a palavra digitada
        tentativa = processarPalavra(tentativa);

        // Valida a entrada
        if (!validarPalavra(tentativa)) {
            std::cout << "Tente novamente.\n";
            continue;
        }

        // Adiciona a tentativa e atualiza o HUD
        hud.adicionarTentativa(tentativa, palavra);
        hud.atualizarTeclado(tentativa, palavra);
        hud.imprimirHUD();

        // Verifica se acertou
        if (tentativa == palavra) {
            std::cout << "\nParabéns! Você acertou a palavra!\n";
            return 0;
        }

        tentativasRestantes--;
    }

    // Se esgotou as tentativas
    hud.setPalavraCorreta(palavra);
    hud.imprimirHUD();
    return 0;
}