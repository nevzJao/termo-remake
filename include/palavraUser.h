#ifndef PALAVRAUSER_H
#define PALAVRAUSER_H

#include <string>
#include <vector>

enum class FeedbackCor {
    VERDE,
    AMARELO,
    CINZA
};

class PalavraUser {
public:
    PalavraUser(const std::string& tentativa);

    bool ehValida() const;
    std::vector<FeedbackCor> compararCom(const std::string& palavraSecreta) const;
    std::string getPalavra() const;

private:
    std::string palavra;
};

#endif // PALAVRAUSER_H
