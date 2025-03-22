#include <iostream>

using namespace std;

// Función que crea una matriz dinámica de tamaño n x n
int** crearMatriz(int n){
    int** matriz = new int*[n]; // Reserva espacio para n filas
    for(int i=0; i<n; ++i){
        matriz[i] = new int[n]; // Para cada fila, reservamos n columnas
    }

    return matriz;
}

// Función que carga la matriz con valores secuenciales desde 1
void cargarMatriz(int** matriz, int n){
    int valor = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = valor++;
        }
    }
}

// Función que imprime la matriz en forma de tabla
void imprimirMatriz(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " "; // Muestra cada elemento seguido de un espacio
        }
        cout << endl;
    }
}

// Función que imprime la matriz en orden inverso (del último elemento al primero)
void imprimirMatrizInversa(int** matriz, int n) {
    int totalElem = n * n;
    for (int i = totalElem - 1; i >= 0; --i) {  // Recorre de atrás hacia adelante
        int fila = i / n; // Calcula la fila original
        int col = i % n; // Calcula la columna original
        cout << "M[" << fila << "][" << col << "] = " << matriz[fila][col] << endl;
    }
}

// Función que libera la memoria dinámica reservada para la matriz
void liberarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz; 
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    if (n > 1) {
        int** matriz = crearMatriz(n);   
        cargarMatriz(matriz, n); 
        imprimirMatriz(matriz, n); 
        imprimirMatrizInversa(matriz, n); 
        liberarMatriz(matriz, n);
    } else {
        cout << "El valor de n debe ser mayor que 1." << endl;
    }

    return 0;
}