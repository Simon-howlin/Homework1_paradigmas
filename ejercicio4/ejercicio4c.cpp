#include <iostream>
#include <chrono>

using namespace std;

#define texto1 "abcdefghijklmnopqrstuvwxyz" // cadena 1 -> abecedario
#define texto2 "abcdefghijklmnopqrstuvwxyz" // cadena 2 -> abecedario
#define texto3 "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz" // cadena 3 -> abecedario x2
#define texto4 "abcdefghijklmnopqrstuvwaaa" // cadena 4 -> abecedario termina en aaa


constexpr bool sonIgualesRecursivo(const char* char1, const char* char2) {
    // Caso base: si llegamos al final de la cadena, son iguales
    if (*char1 == '\0' && *char2 == '\0') return true;

    // Si las longitudes son diferentes, las cadenas no pueden ser iguales
    if (*char1 == '\0' || *char2 == '\0') return false;

    // Si los caracteres en la posición actual son diferentes, las cadenas no son iguales
    if (*char1 != *char2) return false;

    // Llamado recursivo para el siguiente carácter
    return sonIgualesRecursivo(char1 + 1, char2 + 1);
}

// array de valores predefinidos
constexpr bool sonIguales[3] = {sonIgualesRecursivo(texto1, texto2), sonIgualesRecursivo(texto2, texto3), sonIgualesRecursivo(texto3, texto4)};

int main() {
    for (int i = 0; i < 3; i++){
        cout << "prueba numero " << i+1 << ": " << endl;

        // Medición del tiempo para comparación de cadenas idénticas
        auto start = chrono::high_resolution_clock::now();
        bool resultado = sonIguales[i]; // alterna entre i = {0,1,2} para sonIguales[i]
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
        cout << "Comparación de cadenas idénticas tomó: " << elapsed.count() << " nanosegundos." << endl;
        cout << "Resultado: " << (resultado ? "Iguales" : "Diferentes") << endl << endl;
    }

    return 0;
}