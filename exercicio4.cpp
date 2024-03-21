/* Exercício 4 - À partir de uma lista de nomes disponível em um arquivo TXT, transforma-los em nomes no formato citação bibliográfica. Exemplo:

José Antonio Santos Silva
SILVA, José A. S. */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <codecvt>
using namespace std;

// Fun��o para transformar o nome no formato de cita��o bibliogr�fica
string transformarNome(const string &nome) {
    stringstream ss(nome);
    string parte, sobrenome;
    vector<string> nomes;

    // Separando os nomes por espa�os
    while (ss >> parte) {
        if (!parte.empty()) {
            // Transformando a primeira letra em mai�scula
            parte[0] = toupper(parte[0]);
            nomes.push_back(parte);
        }
    }

    // Obtendo o sobrenome (�ltimo elemento do vetor)
    sobrenome = nomes.back();
    nomes.pop_back();

    // Construindo o nome no formato "Sobrenome, Iniciais dos Primeiros Nomes."
    string citacao = sobrenome + ", ";
    for (size_t i = 0; i < nomes.size(); ++i) {
        citacao += nomes[i][0];
        citacao += ". ";
    }
    citacao.pop_back(); // Removendo o espa�o extra no final

    return citacao;
}

int main() {
    // Configura��o do locale para a codifica��o correta (UTF-8)
    setlocale(LC_ALL, "");

    // Configura��o para leitura de arquivos em UTF-8
    wifstream arq("lista1.txt");
    arq.imbue(locale(arq.getloc(), new codecvt_utf8<wchar_t>));

    if (arq.is_open()) {
        wstring linha;
        while (getline(arq, linha)) {
            // Convertendo wstring para string
            wstring_convert<codecvt_utf8<wchar_t>> converter;
            string nome = converter.to_bytes(linha);
            
            // Transforma cada linha da lista
            string nome_formatado = transformarNome(nome);
            
            // Imprime o nome transformado
            cout << nome_formatado << endl;
        }
        arq.close();
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
    return 0;
}
