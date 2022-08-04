// A partir de uma função e um intervalo, realiza-se uma aproximação polinomial
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

class caso_continuo {
    private:
        int resp, grau;
        float xi, xf;
    public:
        caso_continuo () {
            cout << "Escreva a funcao a ser aproximada (polinomio, sem espacos): ";
            // cin >> umastring;
            cout << "Delimite o intervalo ([xi,xf]): ";
            // cin >> otrastring;
            menu();
        }
        void menu () {
            cout << "Escolha o tipo de aproximacao:" << endl;
            cout << "[1] Polinomio tipico (grau a ser escolhido)" << "\t" << 
            "[2] Polinomio personalizado" << endl;
            cout << ">> ";
            cin >> resp;
            resposta();
        }        
        void polinomio_tipico () {
            cout << endl <<  "Grau do polinomio (ate 3): ";
            cin >> grau;
            calcula1();
            if (grau == 2)
                calcula2();
            else if (grau > 2)
                calcula3();
        }
        void polinomio_personalizado () {

        }
        float integral (string f) { // Parte-se do pressuposto que se quer integrar um polinômio

        }
        void calcula1 () {

        }
        void calcula2 () {

        }
        void calcula3 () {

        }        
        void resposta () {
            if (resp == 1)
                polinomio_tipico();
            else
                polinomio_personalizado();
        }
};

int main () {
    caso_continuo obj;

    system("pause");
    return 0;
}
