#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void set_matrix   (int n, float *m);
void print_matrix (int n, float *m);
float determinant (int n, float *m);
bool is_singular  (int n, float *m);
void transposes   (int n, float *cofac, float *trans);
void set_inverse  (int n, float *m, float *inv);

int main () {
    int n;
    float *m, det, *inv;

    cout << "Matrix order >> ";
    cin >> n;

    m = new float[n*n];    
    inv = new float[n*n];    

    set_matrix(n,m);
    print_matrix(n,m);

    if (is_singular(n,m)) {
        cout << "Matrix is singular. Therefore, does not have inverse!" << endl;                
    } else {
        set_inverse(n, m, inv);        
    }

    delete[] m;
    delete[] inv;    

    system("pause");
    return 0;
}

void set_matrix (int n, float *m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a" << i + 1 << j + 1 << ": ";
            cin >> *(m + n*i + j);             
        }
        cout << endl;
    }
}

void print_matrix (int n, float *m) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *m << " ";
            m++;
        }
        cout << endl;
    }
    cout << endl;
}

float determinant (int n, float *m) {
    if (n == 1) {
       return *m;
    } else {
        int nn = n - 1;
        int g, h;
        g = h = 0;

        float *q, det, partial_det;
        q = new float[nn*nn];        
        det = 0;

        for (int k = 0; k < n; k++) { // percorre os elms da 1a linha
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j != k) {                                     
                        *(q + g*nn + h) = *(m + i*n + j); // contador diferente !!!                       
                        h++;
                    }                 
                }
                g++;
                h = 0; // importante !!!
            }
            h = g = 0;         
            partial_det = determinant(nn,q);                                                              
            det += pow(-1, 2 + k)*(*(m + k))*partial_det;
        }        
        return (det);
    }
}

bool is_singular (int n, float *m) {
    float det = determinant(n,m);
    return (det == 0 ? true : false);
}

void transposes (int n, float *cofac, float *trans) {
    int k, l;
    k = l = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            cout << *(cofac + i*n + j) << endl; // teste
            *(trans + k*n + l) = *(cofac + i*n + j);
            l++;
        }
        k++;
        l = 0;
    }
    cout << "transposed:" << endl;
    for (int y = 0; y < n; y++) {
        for (int z = 0; z < n; z++) {
            cout << *trans << " ";
            trans++;
        }
        cout << endl;
    }
}

void set_inverse (int n, float *m, float *inv) {
    float *cofac, *fewer, *trans;
    int nn = n - 1, g, h;
    cofac = new float[n*n];
    fewer = new float[nn*nn];
    trans = new float[n*n];
    g = h = 0;
    for (int li = 0; li < n; li++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (i != li) {
                    for (int j = 0; j < n; j++) {
                        if (j != k) {
                            *(fewer + g*nn + h) = *(m + i*n + j);
                            h++;
                        }
                    }
                    g++;   
                }                
                h = 0;
            }
            *(cofac + li*n + k) = pow(-1, li + k)*determinant(nn, fewer);
            g = h = 0;
        }
    }
    cout << "cofac:" << endl;
    for (int y = 0; y < n; y++) {
        for (int z = 0; z < n; z++) {
            cout << *cofac << " ";
            cofac++;
        }
        cout << endl;
    }
    transposes(n,cofac,trans);
    delete[] cofac;
    delete[] fewer;    
}
