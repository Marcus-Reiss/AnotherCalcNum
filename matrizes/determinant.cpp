// trying to evaluate the determinant of any n x n matrix
// solution method - Laplace
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void set_matrix   (int n, float *m);
void print_matrix (int n, float *m);
float determinant (int n, float *m);

int main () {
    int n;
    float *m, det;

    cout << "Matrix order >> ";
    cin >> n;

    m = new float[n*n];    

    set_matrix(n,m);
    print_matrix(n,m);
    det = determinant(n,m);

    cout << "det(M) = " << det << endl << endl;

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
