#ifndef PALAVRASECRETA_H
#define PALAVRASECRETA_H

#include <string>
#include <vector>

class PalavraSecreta {
private:
    std::string palavra;
    std::vector<std::string> palavrasValidas;

    std::string removerAcentos(const std::string& str);

public:
    PalavraSecreta(const std::string& nomeArquivo);
    std::string getPalavra() const;
};

#endif
