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
    std::map<char, char> mapa = {
        {'Á','A'}, {'À','A'}, {'Â','A'}, {'Ã','A'},
        {'É','E'}, {'Ê','E'},
        {'Í','I'},
        {'Ó','O'}, {'Ô','O'}, {'Õ','O'},
        {'Ú','U'},
        {'Ç','C'},
        {'á','a'}, {'à','a'}, {'â','a'}, {'ã','a'},
        {'é','e'}, {'ê','e'},
        {'í','i'},
        {'ó','o'}, {'ô','o'}, {'õ','o'},
        {'ú','u'},
        {'ç','c'}
    };

    for (auto& c : resultado) {
        if (mapa.find(c) != mapa.end()) {
            c = mapa[c];
        }
    }
    return resultado;
}
