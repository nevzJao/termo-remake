# Termo - Jogo de Adivinhação de Palavras
**Grupo: Isadora Drumond, Júlia Luíza, João Marcos Nevez, Rodrigo Anastácio e Victor Altafin**

## 🎯 Visão Geral

O ***Termo*** é um jogo de adivinhação de palavras executado no terminal. O objetivo é acertar uma palavra secreta de 5 letras, em até **10 tentativas**.

Após cada tentativa, o jogador recebe um feedback visual:
- Letras na posição correta ficam *verdes*.
- Letras que estão na palavra, mas na posição errada, ficam *amarelas*.
- Letras que não estão na palavra ficam *cinzas*.

O projeto é desenvolvido em C++, utilizando conceitos de Programação Orientada a Objetos (POO) e boas práticas de desenvolvimento, com colaboração via GitHub.

---

## 📦 Requisitos

- Compilador C++ (como `g++` ou `clang++`);
- Sistema operacional compatível com terminal (Linux, macOS ou Windows com terminal que suporte ANSI);
- Git instalado (para clonar o repositório).

---

## ⚙️ Como Configurar o Ambiente de Desenvolvimento

1. **Clone o repositório:**

```bash
git clone https://github.com/nevzJao/termo-remake.git
cd termo-remake
```
2. Compile o projeto

Se houver um arquivo `Makefile`:
bash```
make```

Ou, compilando manualmente:
bash```g++ src/*.cpp -o termo```

Execute o jogo:
bash```./termo```


## 🤝 Como Contribuir

1. Faça um fork do projeto;
2. Crie uma branch para sua funcionalidade ou correção:
   bash```git checkout -b minha-feature```
3. Faça seus commits com mensagens claras:
   bash```git commit -m "Adiciona nova funcionalidade"```
4. Envie para seu repositório remoto:
   bash```git push origin minha-feature```
5. Abra um Pull Request explicando suas alterações para que possamos revisar e integrar ao projeto.


## 🗒️ Observações

- O projeto será organizado na pasta `src/`, que contém os arquivos `.cpp` e `.h`;
- As palavras usadas no jogo estão armazenadas em um arquivo externo, como `palavras.txt`.
