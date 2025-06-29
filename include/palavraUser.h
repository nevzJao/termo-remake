#ifndef PALAVRA_USER_H
#define PALAVRA_USER_H

#include "Color.h"  // Inclua o novo arquivo
#include <string>
#include <vector>

class PalavraUser {
private:
    std::string palavra;
    std::vector<Color> cores;

public:
    PalavraUser(const std::string& tentativa, const std::string& palavraSecreta);
    std::string getPalavra() const;
    Color getColor(size_t index) const;
    size_t size() const;
};

#endif // PALAVRA_USER_H
