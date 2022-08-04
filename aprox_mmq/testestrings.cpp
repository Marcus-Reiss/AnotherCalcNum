// testes com strings
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main () {
    string pol1, pol2, pol3, pol;
    pol1 = "123*x^2";
    pol2 = "+74*x^3";
    pol3 = pol1.append(pol2);
    int pos1 = pol1.find('*');
    cout << "pol3: " << pol3;
    cout << endl << "pos1: " << pos1 << endl;

    string a = pol3.substr(0 , pos1);
    string b = pol3.substr(pol3.find('+') + 1, pol3.find('*') - 1);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "polinomio (sem espacos): ";
    cin >> pol;
    string coef2 = pol.substr(pol.find('+') + 1, pol.find('*', pol.find('*') + 1) - (pol.find('+') + 1));
    string coef3 = pol.substr(pol.find('+', pol.find('+') + 1) + 1, pol.find('*')); // errado ! (length)
    string exp3  = pol.substr(pol.find('^', pol.find('^', pol.find('^') + 1) + 1) + 1, 1);
    
    cout << "coef2: " << coef2 << endl << "coef3: " << coef3 << endl << "exp3: " << exp3 << endl;

    string pol4, sp4;
    pol4 = "2*x^2+3*x^3+5*x^4+71*x^1+16*x^5+23*x^4";
    int conta, pos;
    pos = conta = 0;
    while (true) {
        pos = pol4.find('+', pos + 1);
        if (pos == string::npos)
            break;        
        conta++;        
    }
    cout << endl << "qtde de +: " << conta << endl;

    system("pause");
    return 0;
}
