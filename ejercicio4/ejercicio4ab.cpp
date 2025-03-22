#include <iostream>
#include <chrono>

using namespace std;

bool sonIgualesRecursivo(const char* char1, const char* char2) {
    // Caso base: si llegamos al final de la cadena, son iguales
    if (*char1 == '\0' && *char2 == '\0') return true;

    // Si las longitudes son diferentes, las cadenas no pueden ser iguales
    if (*char1 == '\0' || *char2 == '\0') return false;

    // Si los caracteres en la posición actual son diferentes, las cadenas no son iguales
    if (*char1 != *char2) return false;

    // Llamado recursivo para el siguiente carácter
    return sonIgualesRecursivo(char1 + 1, char2 + 1);
}

int main() {
    // array de los textos a usar
    char* textos [4] = {"abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwaaa"};

    for (int i = 0; i < 3; i++){
        cout << "prueba numero " << i+1 << ": " << endl;

        // Medición del tiempo para comparación de cadenas idénticas
        auto start = chrono::high_resolution_clock::now();
        bool resultado = sonIgualesRecursivo(textos[i], textos[i+1]); // alterna entre los textos 
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
        cout << "Comparación de cadenas idénticas tomó: " << elapsed.count() << " nanosegundos." << endl;
        cout << "Resultado: " << (resultado ? "Iguales" : "Diferentes") << endl << endl;
    }

    return 0;
}