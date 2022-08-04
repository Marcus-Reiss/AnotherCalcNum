// aproxima um conjunto de pontos por uma função da forma f(x) = aexp(bx)
// processo -> ln(f) = ln(a) + bx -> F = ln(f) = a0g0(x) + a1g1(x) onde a0 = ln(a); a1 = b; g0 = 1; g1 = x

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class aexp {
    private:
        float g0[10], g1[10], f[10], F[10];
        float g0g0, g0g1, g1g1, g0F, g1F;
        float a0, a1, a, b;
        int tam;
    public:
        aexp () {
            cout << "Numero de pontos" << endl << ">> ";
            cin >> tam;
            for (int k = 0; k < tam; k++)        // g0
                g0[k] = 1;
            cout << endl << "Vetor x:" << endl;
            for (int k = 0; k < tam; k++) {      // g1
                cout << "x" << k + 1 << ": ";
                cin >> g1[k];
            }
            cout << endl << "Vetor y:" << endl;
            for (int k = 0; k < tam; k++) {      // f
                cout << "y" << k + 1 << ": ";
                cin >> f[k];
            }
            for (int k = 0; k < tam; k++)        // F
                F[k] = log(f[k]);
            g0g0 = g0g1 = g1g1 = g0F = g1F = 0;
            prod_int();            
        }
        void prod_int () {
            for (int i = 0; i < tam; i++) {
                g0g0 += g0[i]*g0[i];
                g0g1 += g0[i]*g1[i];
                g1g1 += g1[i]*g1[i];
                g0F  += g0[i]*F[i];
                g1F  += g1[i]*F[i];
            }
            sistema();
        }
        void sistema () {
           a1 = (g1F - (g0g1*g0F)/g0g0)*pow((g1g1 - pow(g0g1,2)/g0g0),-1);
           a0 = (g0F - g0g1*a1)/g0g0;
           a = exp(a0);
           b = a1;
           func();
        }
        void func () {
            cout << endl;
            cout << "A funcao da forma aexp(bx) que melhor aproxima os pontos: " <<
            a << "exp(" << b << "x)" << endl << endl;
        }
};

int main () {
    aexp obj;
    
    system("pause");
    return 0;
}
