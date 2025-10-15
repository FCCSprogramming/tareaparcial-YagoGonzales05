#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX=10;

void leerMatriz(float (*M)[MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "D[" << i+1 << "][" << j+1 << "] = ";
            cin >> *(*(M + i) + j);
        }
    }
}


void mostrarMatriz(float (*M)[MAX], int N, string nombre) {
    cout << "\n" << nombre << " =\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(8) << fixed << setprecision(2) << *(*(M + i) + j);
        }
        cout << endl;
    }
}

void transpuesta(float (*D)[MAX], float (*DT)[MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(DT + j) + i) = *(*(D + i) + j);
        }
    }
}


void multiplicar(float (*A)[MAX], float (*B)[MAX], float (*R)[MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float suma = 0;
            for (int k = 0; k < N; k++) {
                suma += (*(*(A + i) + k)) * (*(*(B + k) + j));
            }
            *(*(R + i) + j) = suma;
        }
    }
}


float traza(float (*M)[MAX], int N) {
    float t = 0;
    for (int i = 0; i < N; i++)
        t += *(*(M + i) + i);
    return t;
}

float energia(float (*M)[MAX], int N) {
    float suma = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            suma += pow(*(*(M + i) + j), 2);
    return suma / (N * N);
}


int main() {
    int N;
    float D[MAX][MAX], DT[MAX][MAX], I[MAX][MAX];

    cout << "Ingrese el tamaño de la matriz (N <= 10): ";
    cin >> N;
   cout<<endl;
    cout << "Ingrese los valores de la matriz D:\n";
    leerMatriz(D, N);
    cout<<endl;
    transpuesta(D, DT, N);
    multiplicar(D, DT, I, N);

    mostrarMatriz(D, N, "Matriz D (original)");
    mostrarMatriz(DT, N, "Matriz D^T (transpuesta)");
    mostrarMatriz(I, N, "Matriz I = D * D^T");

    float tr = traza(I, N);
    float E = energia(I, N);
    cout<<endl;
    cout << "Traza(I) = " << tr << endl;
    cout << "Energia normalizada = " << fixed << setprecision(4) << E << endl;

    return 0;
}
