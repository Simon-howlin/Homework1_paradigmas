#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define los niveles de severidad disponibles para los mensajes de log
enum NivelSeveridad {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    SECURITY
};

// Devuelve una etiqueta de texto correspondiente al nivel de severidad
string obtenerEtiqueta(NivelSeveridad nivel) {
    switch(nivel) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        case SECURITY: return "SECURITY";
        default: return "UNKNOWN";
    }
}

// Registra un mensaje en el archivo de log con el nivel especificado
void logMessage(const string& mensaje, NivelSeveridad nivel) {
    ofstream archivoLog("log.txt", ios::app);   // Abre o crea el archivo en modo append
    if (archivoLog.is_open()) {
        archivoLog << "[" << obtenerEtiqueta(nivel) << "] " << mensaje << endl;
        archivoLog.close();
        cout << "Mensaje logueado: [" << obtenerEtiqueta(nivel) << "] " << mensaje << endl;
    } else {
        cerr << "Error al abrir el archivo de log." << endl;
    }
}

// Registra un mensaje de error incluyendo nombre de archivo y línea
void logMessage(const string& mensajeError, const string& archivo, int linea) {
    string mensaje = mensajeError + " en archivo: " + archivo + ", línea: " + to_string(linea);
    logMessage(mensaje, ERROR);
}

// Registra un mensaje de acceso relacionado a un usuario, con nivel SECURITY
void logMessage(const string& mensajeAcceso, const string& usuario) {
    string mensaje = "Usuario: " + usuario + ", Acción: " + mensajeAcceso;
    logMessage(mensaje, SECURITY);
}

int main() {

    // Registra varios eventos con diferentes niveles de severidad
    logMessage("El sistema ha iniciado correctamente.", INFO);
    logMessage("Variable x tiene un valor inesperado.", DEBUG);
    logMessage("Espacio en disco al 80%.", WARNING);
    logMessage("No se pudo abrir el archivo de configuración.", ERROR);
    logMessage("Fallo crítico: pérdida de datos detectada.", CRITICAL);

    // Registra un mensaje de error incluyendo información de archivo y línea
    logMessage("Error al leer el archivo", "config.txt", 42);

    // Registra eventos de seguridad relacionados a intentos de acceso
    logMessage("Access Granted", "admin");
    logMessage("Access Denied", "unknown_user");

    // Maneja una excepción en tiempo de ejecución y registra el error capturado
    try {
        throw runtime_error("Fallo inesperado durante la ejecución.");
    } catch (const exception& e) {
        logMessage(e.what(), __FILE__, __LINE__);
        return 1;
    }

    return 0;
}
