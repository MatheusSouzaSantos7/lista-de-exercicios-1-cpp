#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

// Função para transformar o nome no formato de agenda telefônica
string transformarNome(const string &nome) {
    // Encontra a posição do último espaço na string
    size_t posUltimoEspaco = nome.find_last_of(' ');

    if (posUltimoEspaco != string::npos) {
        // Extrai o último sobrenome
        string ultimoSobrenome = nome.substr(posUltimoEspaco + 1);

        // Extrai os nomes e o(s) primeiro(s) sobrenome(s)
        string nomes = nome.substr(0, posUltimoEspaco);

        // Formata no formato "Sobrenome, Nomes"
        return ultimoSobrenome + ", " + nomes;
    }

    // Se não houver espaço na string, retorna o próprio nome
    return nome;
}

int main(int argc, char** argv){
    setlocale(LC_ALL, "");
    
    string nome;
	
    ifstream arq("lista1.txt");

    if (arq.is_open()) {
        string linha;
        while (getline(arq, linha)) {
            // Transforma cada linha da lista
            nome = transformarNome(linha);
            
            // Imprime o nome transformado
            cout << nome << endl;
        }
        arq.close();
    } else {
        cout << "Erro ao abrir o arquivo";
    }
    return 0;
}