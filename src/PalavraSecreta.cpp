#include "../include/PalavraSecreta.h"
#include <fstream>
#include <algorithm>
#include <random>
#include <iostream>
#include <map>

PalavraSecreta::PalavraSecreta(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::string linha;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de palavras.\n";
        exit(1);
    }

    while (arquivo >> linha) {
        if (linha.size() == 5) {
            std::transform(linha.begin(), linha.end(), linha.begin(), ::toupper);
            palavrasValidas.push_back(linha);
        }
    }

    if (palavrasValidas.empty()) {
        std::cerr << "Nenhuma palavra válida encontrada.\n";
        exit(1);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, palavrasValidas.size() - 1);

    palavra = palavrasValidas[dist(gen)];
    palavra = removerAcentos(palavra);
}

std::string PalavraSecreta::getPalavra() const {
    return palavra;
}

std::string PalavraSecreta::removerAcentos(const std::string& str) {
    std::string resultado = str;
    
    // Create a mapping of accented characters to their non-accented equivalents
    static const std::map<std::string, char> mapa = {
        {"Á", 'A'}, {"À", 'A'}, {"Â", 'A'}, {"Ã", 'A'},
        {"É", 'E'}, {"Ê", 'E'},
        {"Í", 'I'},
        {"Ó", 'O'}, {"Ô", 'O'}, {"Õ", 'O'},
        {"Ú", 'U'},
        {"Ç", 'C'},
        {"á", 'a'}, {"à", 'a'}, {"â", 'a'}, {"ã", 'a'},
        {"é", 'e'}, {"ê", 'e'},
        {"í", 'i'},
        {"ó", 'o'}, {"ô", 'o'}, {"õ", 'o'},
        {"ú", 'u'},
        {"ç", 'c'}
    };

    // Iterate through the string and replace accented characters
    for (size_t i = 0; i < resultado.length(); ) {
        // Check for multi-byte sequences (assuming UTF-8)
        if ((resultado[i] & 0x80) != 0) {  // If high bit is set (UTF-8 multi-byte)
            std::string key;
            // Get the full multi-byte character (2 bytes for these accented chars)
            if (i + 1 < resultado.length()) {
                key = resultado.substr(i, 2);
                auto it = mapa.find(key);
                if (it != mapa.end()) {
                    resultado[i] = it->second;
                    resultado.erase(i + 1, 1);  // Remove the second byte
                }
            }
            i++;
        } else {
            // Regular ASCII character
            i++;
        }
    }
    
    return resultado;
}
