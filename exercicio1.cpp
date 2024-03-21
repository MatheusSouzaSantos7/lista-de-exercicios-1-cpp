/* Exercício 1  - Receber através de digitação uma mensagem. 
Apresentar esta mensagem, centralizada, na linha 5 da tela.
À partir daí, cada letra desta mensagem deverá "cair", da linha 5 até a linha 20, simulando uma "cascata". Ao final, a mensagem deverá estar toda apresentada na linha 20. */

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void gotoxy(short x, short y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void waitHalfSecond() {
    Sleep(500); // Espera meio segundo
}

int main() {
    setlocale(LC_ALL, "");

    string msg;
    cout << "Digite uma mensagem: ";
    getline(cin, msg);

    int screenWidth = 230; // Largura da tela, ajuste conforme necess�rio
    int msgWidth = msg.length();
    int posX = (screenWidth - msgWidth) / 2;
    int posY = 5;

    gotoxy(posX, posY);
    cout << msg;

    // Efeito cascata
    for (char& c : msg) {
        posY++;
        gotoxy(posX, posY);
        cout << c;
        waitHalfSecond(); // Espera meio segundo
        gotoxy(posX, posY);
        cout << ' '; // Apaga a letra
    }

    return 0;
}