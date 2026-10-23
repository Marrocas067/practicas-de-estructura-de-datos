// create by Marrocas_067
// la fumcion de este programa es poder realizar un juego del gato, donde se pueda jugar entre dos jugadores y se pueda ver el tablero de juego


#include <iostream>
#include <limits>
using namespace std;

// Funcion para crear tablero
void mostrarTablero(char tablero[3][3]) {
    cout << "\n";

    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            cout << " " << tablero[fila][columna] << " ";

            if (columna < 2) {
                cout << "|";
            }
        }

        cout << "\n";

        if (fila < 2) {
            cout << "---+---+---\n";
        }
    }

    cout << "\n";
}

// Funcion para verificar si hay un ganador
bool hayGanador(char tablero[3][3], char jugador) {

    // Revisar las tres filas
    for (int fila = 0; fila < 3; fila++) {
        if (tablero[fila][0] == jugador &&
            tablero[fila][1] == jugador &&
            tablero[fila][2] == jugador) {
            return true;
        }
    }

    // Revisar las tres columnas
    for (int columna = 0; columna < 3; columna++) {
        if (tablero[0][columna] == jugador &&
            tablero[1][columna] == jugador &&
            tablero[2][columna] == jugador) {
            return true;
        }
    }

    // Revisar la diagonal principal
    if (tablero[0][0] == jugador &&
        tablero[1][1] == jugador &&
        tablero[2][2] == jugador) {
        return true;
    }

    // Revisar la diagonal secundaria
    if (tablero[0][2] == jugador &&
        tablero[1][1] == jugador &&
        tablero[2][0] == jugador) {
        return true;
    }

    return false;
}

// Funcion para verificar si quedan casillas libres
bool tableroLleno(char tablero[3][3]) {
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            if (tablero[fila][columna] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// Funcion principal del juego
int main() {
    char tablero[3][3];

    // Llenar todas las casillas con espacios vacios
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            tablero[fila][columna] = ' ';
        }
    }

    char jugador = 'X';
    int fila, columna;
    bool terminado = false;

    cout << "=== JUEGO DEL GATO ===\n";
    cout << "Ingresa la fila y la columna del 1 al 3.\n";

    // El juego continua mientras no haya ganador ni empate
    while (!terminado) {
        mostrarTablero(tablero);

        cout << "Turno del jugador " << jugador << "\n";

        // Validar la jugada del jugador actual
        while (true) {
            cout << "Ingresa la fila (1-3): ";

            if (!(cin >> fila)) {
                cout << "Entrada invalida. Ingresa un numero.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cout << "Ingresa la columna (1-3): ";

            if (!(cin >> columna)) {
                cout << "Entrada invalida. Ingresa un numero.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            // Comprobar que la posicion este dentro del tablero
            if (fila < 1 || fila > 3 ||
                columna < 1 || columna > 3) {
                cout << "Posicion fuera del tablero. Intenta otra vez.\n";
                continue;
            }

            // Convertir las posiciones a indices de la matriz
            fila--;
            columna--;

            // Comprobar que la casilla este libre
            if (tablero[fila][columna] != ' ') {
                cout << "Esa casilla ya esta ocupada. Intenta otra vez.\n";
                fila++;
                columna++;
                continue;
            }

            // Registrar la jugada
            tablero[fila][columna] = jugador;
            break;
        }

        // Comprobar si el jugador actual gano
        if (hayGanador(tablero, jugador)) {
            mostrarTablero(tablero);
            cout << "¡El jugador " << jugador << " ha ganado!\n";
            terminado = true;
        }

        // Comprobar si hay empate
        else if (tableroLleno(tablero)) {
            mostrarTablero(tablero);
            cout << "¡Empate! No quedan casillas libres.\n";
            terminado = true;
        }
        else {
            // Cambiar de jugador
            if (jugador == 'X') {
                jugador = 'O';
            } else {
                jugador = 'X';
            }
        }
    }

    cout << "Fin de la partida.\n";

    return 0;
}
