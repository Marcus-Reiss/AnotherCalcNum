#include <iostream>
#include <iomanip>
using namespace std;

void aloca_matriz (int n, float *m);
void print_matriz (int n, float *m);

int main () {
    int n;    
    float *m;

    cout << "Ordem da matriz >> ";
    cin >> n;

    m = new float[n*n];
    aloca_matriz(n, m);
    print_matriz(n, m);

    system("pause");
    return 0;
}

void aloca_matriz (int n, float *m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a" << i + 1 << j + 1 << ": ";
            cin >> *(m + n*i + j);
        }
        cout << endl;
    }
}

void print_matriz (int n, float *m) {
    cout << endl << "Imprimindo a matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *m << " ";
            m++;
        }
        cout << endl;
    }
}
