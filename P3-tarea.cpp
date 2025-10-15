#include <iostream>
#include <iomanip>
using namespace std;

const int MAX=100;

void leerMediciones(int *ids, float *valores, int n) {
    for (int i = 0; i < n; i++) {
        cout << "ID del sensor [" << i + 1 << "]: ";
        cin >> *(ids + i);
        cout << "Valor medido CO2 [" << i + 1 << "]: ";
        cin >> *(valores + i);
    }
}

void verMediciones(int *ids, float *valores, int n, string titulo) {
    cout << "\n" << titulo << "\n";
    cout << left << setw(10) << "ID" << setw(10) << "CO2" << endl;
    cout << "--------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << *(ids + i)
             << setw(10) << fixed << setprecision(2) << *(valores + i)
             << endl;
    }
}


void merge(int *ids, float *valores, int izq, int mid, int der) {
    int n1 = mid - izq + 1;
    int n2 = der - mid;

    int L_id[MAX], R_id[MAX];
    float L_val[MAX], R_val[MAX];

    for (int i = 0; i < n1; i++) {
        L_id[i] = *(ids + izq + i);
        L_val[i] = *(valores + izq + i);
    }
    for (int j = 0; j < n2; j++) {
        R_id[j] = *(ids + mid + 1 + j);
        R_val[j] = *(valores + mid + 1 + j);
    }

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (L_id[i] <= R_id[j]) {
            *(ids + k) = L_id[i];
            *(valores + k) = L_val[i];
            i++;
        } else {
            *(ids + k) = R_id[j];
            *(valores + k) = R_val[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        *(ids + k) = L_id[i];
        *(valores + k) = L_val[i];
        i++; k++;
    }
    while (j < n2) {
        *(ids + k) = R_id[j];
        *(valores + k) = R_val[j];
        j++; k++;
    }
}

void mergeSort(int *ids, float *valores, int izq, int der) {
    if (izq < der) {
        int mid = (izq + der) / 2;
        mergeSort(ids, valores, izq, mid);
        mergeSort(ids, valores, mid + 1, der);
        merge(ids, valores, izq, mid, der);
    }
}

void buscarMediciones(int *ids, float *valores, int n, int objetivo) {
    int izq = 0, der = n - 1, mid;
    bool encontrado = false;

    while (izq <= der) {
        mid = (izq + der) / 2;
        if (*(ids + mid) == objetivo) {
            encontrado = true;
            break;
        } else if (*(ids + mid) < objetivo)
            izq = mid + 1;
        else
            der = mid - 1;
    }

    if (!encontrado) {
        cout << "\nNo se encontraron mediciones para el sensor " << objetivo << ".\n";
        return;
    }

    int i = mid;
    while (i > 0 && *(ids + i - 1) == objetivo)
        i--;

    cout << "\nMediciones del sensor " << objetivo << ":\n";
    cout << left << setw(10) << "ID" << setw(10) << "CO2" << endl;
    cout << "--------------------\n";

    while (i < n && *(ids + i) == objetivo) {
        cout << left << setw(10) << *(ids + i)
             << setw(10) << fixed << setprecision(2) << *(valores + i)
             << endl;
        i++;
    }
}

int main() {
    int n;
    int ids[MAX];
    float valores[MAX];

    cout << "Ingrese el número de mediciones (max 100): ";
    cin >> n;

    leerMediciones(ids, valores, n);

    verMediciones(ids, valores, n, "Lista original");

    mergeSort(ids, valores, 0, n - 1);

    mostrarMediciones(ids, valores, n, "Lista ordenada por ID");

    int buscarID;
    cout<<endl;
    cout << "Ingrese el ID de sensor a buscar: ";
    cin >> buscarID;

    buscarMediciones(ids, valores, n, buscarID);

    return 0;
}
