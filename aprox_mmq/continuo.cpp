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
        int vcoef_t[10], vexp_t[10], vcoef_aux[10];
        float xi, xf, inte;
        string xixf, vint[2], xixf_aux;
        int vin_aux[10], vint_t[2], sinal;
        bool fst, snd, both, exist;
        float ak[4], bk[3], a, b, c;
        string pint, p1modelo, p2modelo;         
    public:
        caso_continuo () {
            cout << "Escreva a funcao a ser aproximada (polinomio, sem espacos e sem sinais negativos):" << endl;
            cout << ">> ";
            cin >> pol;
            cout << "Delimite o intervalo ([xi,xf]): ";
            cin >> xixf;
            fst = snd = both = exist = false;
            menu();
        }
        void menu () {
            cout << "Escolha o grau do polinomio de aproximacao:" << endl;
            cout << "[1] Polinomio do primeiro grau" << "\t" << 
            "[2] Polinomio do segundo grau" << endl;
            cout << ">> ";
            cin >> grau;
            calcula();
        }
        float integral (string f, int incr) { // Parte-se do pressuposto que se quer integrar um polinômio
            n_termos(f);            
            for (int k = 0; k < numt; k++) {
                vcoef[k] = f.substr(vpos_plus[k] + 1, vpos_ast[k] - (vpos_plus[k] + 1));
                vexp[k]  = f.substr(vpos_ast[k] + 3, 1); // Considerando expoentes na casa das unidades
            }            
            analisa_sinal();            
            transforma(exist,fst,snd,both);
            for (int k = 0; k < numt; k++) {
                vexp_t[k] += incr;
            }
            inte = 0;
            for (int i = 0; i < numt; i++) {
                inte += vcoef_t[i]*(pow(xf, vexp_t[i] + 1) - pow(xi, vexp_t[i] + 1))/(vexp_t[i] + 1);
            }
            return (inte);            
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
        void transforma (bool exist, bool fst, bool snd, bool both) {
            for (int i = 0; i < numt; i++) {  // transforma o vetor dos expoentes
                for (int j = 0; j < 10; j++) {
                    if (st[j] == vexp[i]) {
                        vexp_t[i] = nt[j];
                        break;
                    }
                }                
            }

            for (int l = 0; l < numt; l++) // inicializando vcoef_t
                vcoef_t[l] = 0;         
                            
            for (int i = 0; i < numt; i++) { // transforma o vetor dos coeficientes
                for (int j = 0; j < vcoef[i].length(); j++) {
                    for (int k = 0; k < 10; k++) {
                        if (st[k] == vcoef[i].substr(j,1)) {
                            vcoef_aux[j] = nt[k];
                            break;
                        }                   
                    }                                       
                }
                for (int m = 0; m < vcoef[i].length(); m++)
                    vcoef_t[i] += vcoef_aux[vcoef[i].length() - (m + 1)]*pow(10,m);              
            }
            
            for (int l = 0; l < 2; l++) // inicializando vint_t
                vint_t[l] = 0;

            for (int i = 0; i < 2; i++) { // transforma o vetor intervalo
                for (int j = 0; j < vint[i].length(); j++) {
                    for (int k = 0; k < 10; k++) {
                        if (st[k] == vint[i].substr(j,1)) {
                            vin_aux[j] = nt[k];
                            break;
                        }
                    }
                }                
                for (int m = 0; m < vint[i].length(); m++)
                    vint_t[i] += vin_aux[vint[i].length() - (m + 1)]*pow(10,m);
            }
            if (exist) {
                if (fst) {
                    vint_t[0] *= -1;
                } else if (snd) {
                    vint_t[1] *= -1;
                } else {
                    vint_t[0] *= -1;
                    vint_t[1] *= -1;}                
            }
            xi = vint_t[0];
            xf = vint_t[1];            
        }

        void analisa_sinal () {
            sinal = xixf.find('-');
            if (sinal == string::npos) { // sem sinal                
                vint[0] = xixf.substr(1, xixf.find(',') - 1);
                vint[1] = xixf.substr(xixf.find(',') + 1, xixf.length() -1 - (xixf.find(',') + 1));
            } else {                
                exist = true;
                xixf_aux = xixf;
                if (xixf_aux.replace(sinal,1,"hey").find('-') != string::npos) { // dois sinais                    
                    both = true;
                    vint[0] = xixf.substr(2, xixf.find(',') - 2);
                    vint[1] = xixf.substr(xixf.find(',') + 2, xixf.length() -1 - (xixf.find(',') + 2));
                } else if (sinal < xixf.find(',')) { // um sinal antes da vírgula
                    fst = true;
                    vint[0] = xixf.substr(2, xixf.find(',') - 2);
                    vint[1] = xixf.substr(xixf.find(',') + 1, xixf.length() -1 - (xixf.find(',') + 1));
                } else { // um sinal depois da vírgula
                    snd = true;
                    vint[0] = xixf.substr(1, xixf.find(',') - 1);
                    vint[1] = xixf.substr(xixf.find(',') + 2, xixf.length() -1 - (xixf.find(',') + 2));
                }                             
            }
        }                      
        
        void calcula () {
            pint = "1*x^0"; // matriz A
            for (int i = 0; i < 4; i++) {
                ak[i] = integral(pint, i);
            }
            for (int j = 0; j < 3; j++) {
                bk[j] = integral(pol, j);
            }
            resolve_sistema();                                      
        }

        void resolve_sistema () {
            float a0, a1, a2, a3, a4, b1, b2, b3, t1, t2;
            a0 = ak[0]; a1 = ak[1]; a2 = ak[2]; a3 = ak[3]; a4 = ak[4];
            b1 = bk[0]; b2 = bk[1]; b3 = bk[2];
            if (grau == 1) {
                a = (a1*b2 - a2*b1)/(pow(a1,2) - a0*a2);
                b = (b1 - a0*a)/a1;
            } else {
                t1 = (a2*b3 - a3*b2)*(a2*a0 - pow(a1,2)) - (pow(a2,2) - a1*a3)*(a2*b1 - a1*b2);
                t2 = (a4*a2 - pow(a3,2))*(a2*a0 - pow(a1,2)) - pow((pow(a2,2) - a1*a3), 2);
                c  = t1/t2;
                a  = (a2*b1 - a1*b2 - (pow(a2,2) - a1*a3)*c)/(a2*a0 - pow(a1,2));
                b  = (b2 - a1*a - a3*c)/a2;
            }
            imprime_polinomio();
        }

        void imprime_polinomio () {
            cout << endl << "Polinomio aproximador: ";
            if (grau == 1) {
                cout << a << " + " << b << "x" << endl;                
            } else {
                cout << a << " + " << b << "x + " << c << "x^2" << endl;
            }
        }        
};

int main () {
    caso_continuo obj;

    system("pause");
    return 0;
}
