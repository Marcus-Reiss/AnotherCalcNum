#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main () {
    string nome;
    cout << "Escreve seu nome ae" << endl << ">> ";
    cin >> nome;
    cout << endl << "Aqui seu nome: " << nome << endl;

    float a, b, c;
    a = 2; b = 3; c = 1;
    cout << endl << "resultado: " << (a*b - c)/pow(a,2) << endl;

    system("pause");
    return 0;
}
