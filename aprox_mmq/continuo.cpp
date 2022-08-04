// A partir de uma função e um intervalo, realiza-se uma aproximação polinomial
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

class caso_continuo {
    private:
        int resp, grau, cont, numt, pos;
        string pol, vcoef[10], vexp[10];
        string st[10] = {"0","1","2","3",
        "4","5","6","7","8","9"};
        int nt[10] = {0,1,2,3,4,5,6,7,8,9};
        int vpos_plus[10], vpos_ast[10];
        int vcoef_t[10], vexp_t[10], vexp_aux[10];
        float xi, xf, inte;
    public:
        caso_continuo () {
            cout << "Escreva a funcao a ser aproximada (polinomio, sem espacos): ";
            cin >> pol;
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
            // resposta();
            integral(pol);
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
        void integral (string f) { // Parte-se do pressuposto que se quer integrar um polinômio MUDAR PARA FLOAT
            n_termos(f);
            int c = -1;
            for (int k = 0; k < numt; k++) {
                vcoef[k] = f.substr(vpos_plus[k] + 1, vpos_ast[k] - (vpos_plus[k] + 1));
                vexp[k]  = f.substr(vpos_ast[k] + 3, 1); // Considerando expoentes na casa das unidades
            }
            inte = 0;
            //for (int i = 0; i < numt; i++) {
            //    inte += vcoef[i]*pow((xf - xi), vexp[i] + 1)/(vexp[i] + 1);
            //}
        }
        void n_termos (string f) { // f é da forma "8*x^0+1*x^2+3*x^1+24*x^7" (exemplo)
            pos = cont = 0;
            vpos_plus[0] = -1;            
            while (true) {
                pos = f.find('+', pos + 1);
                if (pos == string::npos)
                    break;
                vpos_plus[cont + 1] = pos; // guarda a posição do '+'
                cont++;
            }            
            numt = cont + 1;
            pos = cont = 0;
            while (true) {
                pos = f.find('*', pos + 1);
                if (pos == string::npos)
                    break;
                vpos_ast[cont] = pos; // guarda a posição do '*'
                cont++;
            }            
        }
        void transforma () {
            for (int i = 0; i < numt; i++) {
                for (int j = 0; j < 10; j++) {
                    if (st[j] == vexp[i]) {
                        vexp_t[i] = nt[j];
                        break;
                    }
                }                
            }
            for (int l = 0; l < numt; l++) // inicializando vexp_t
                vexp_t[l] = 0;
            for (int i = 0; i < numt; i++) {
                for (int j = 0; j < vcoef[i].length(); j++) {
                    for (int k = 0; k < 10; k++) {
                        if (st[k] == vcoef[i].substr(j,1)) {
                            vexp_aux[j] = nt[k];
                            break;
                        }                   
                    }
                   // vexp_t[i] += vexp_aux[vcoef[i].length() - 1]                   
                }                
            }
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
