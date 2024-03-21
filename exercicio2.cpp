/*
Exercício 2  - Receber através de digitação uma mensagem. 
Informar se esta mensagem é ou não um dado palíndromo (no caso de haver espaços no texto, desconsiderá-los para a verificação). Exemplos:

OVO
ARARA
SOCORRAM ME SUBI NO ONIBUS EM MARROCOS
*/
#include <iostream>
#include <string>
#include <algorithm>

// Função para remover espaços de uma string
void removeEspacos(std::string &str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

// Função para verificar se uma string é um palíndromo
bool ehPalindromo(const std::string &str) {
    std::string strSemEspacos = str;
    removeEspacos(strSemEspacos);
    std::string strReversa = strSemEspacos;
    std::reverse(strReversa.begin(), strReversa.end());
    return strSemEspacos == strReversa;
}

int main() {
    std::string mensagem;

    std::cout << "Digite a mensagem: ";
    std::getline(std::cin, mensagem);

    if (ehPalindromo(mensagem)) {
        std::cout << "A mensagem digitada e um palindromo." << std::endl;
    } else {
        std::cout << "A mensagem digitada nao e um palindromo." << std::endl;
    }

    return 0;
}
