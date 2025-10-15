#include <iostream>
#include <cstring>
using namespace std;

const int MAX_FRASES = 5;
const int MAX_LONG = 100;
const int MAX_PALABRA = 20;


void leerFrases(char frases[][MAX_LONG], int n);
int contarPalabra(const char frase[], const char palabra[]);
int buscarMayor(int conteos[], int n);
void mostrarResultados(char frases[][MAX_LONG], int conteos[], int n, const char palabra[]);

int main() {
    int n;
    cout << "Ingrese la cantidad de frases (max 5): ";
    cin >> n;
    cin.ignore();

    char frases[MAX_FRASES][MAX_LONG];
    leerFrases(frases, n);

    char palabra[MAX_PALABRA];
    cout << "\nIngrese la palabra clave: ";
    cin.getline(palabra, MAX_PALABRA);

    int conteos[MAX_FRASES];
    for (int i = 0; i < n; i++)
        conteos[i] = contarPalabra(frases[i], palabra);

    mostrarResultados(frases, conteos, n, palabra);

    return 0;
}


void leerFrases(char frases[][MAX_LONG], int n) {
    cout << "\nIngrese las frases:\n";
    for (int i = 0; i < n; i++) {
        cout << "Frase " << i + 1 << ": ";
        cin.getline(frases[i], MAX_LONG);
    }
}


int contarPalabra(const char frase[], const char palabra[]) {
    char copia[MAX_LONG];
    strcpy(copia, frase);

    const char *delim = " ,.;:!?";
    char *token = strtok(copia, delim);

    int contador = 0;
    while (token != NULL) {
        if (strcmp(token, palabra) == 0)
            contador++;
        token = strtok(NULL, delim);
    }
    return contador;
}


int buscarMayor(int conteos[], int n) {
    int mayor = conteos[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (conteos[i] > mayor) {
            mayor = conteos[i];
            pos = i;
        }
    }
    return pos;
}


void mostrarResultados(char frases[][MAX_LONG], int conteos[], int n, const char palabra[]) {
    cout << "\nResultados:\n";
    bool encontrada = false;
    for (int i = 0; i < n; i++) {
        cout << "Frase " << i + 1 << ": \"" << frases[i] << "\" -> " << conteos[i] << " apariciones.\n";
        if (conteos[i] > 0) encontrada = true;
    }

    if (!encontrada) {
        cout << "\nLa palabra \"" << palabra << "\" no aparece en ninguna frase.\n";
    } else {
        int pos = buscarMayor(conteos, n);
        cout << "La frase con mas apariciones es:\n\"" << frases[pos] << endl;
        cout << "Longitud de la frase: " << strlen(frases[pos]) << " caracteres.\n";
    }
}
