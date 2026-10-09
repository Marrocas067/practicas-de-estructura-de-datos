// la funcion de este codigo es poder realizar una lista de calificaciones registrando
// alumnos, calificaciones y promedios

#include <iostream>
#include <string>

using namespace std;

int main(){

    int option;

    do{
        cout << "\nSistema de calificaciones escolares" << endl;
        cout << "1. Ingresar calificaciones" << endl;
        cout << "2. Ver informacion del programa" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";

        cin >> option;

        switch(option){

            case 1: {

                string nombres;
                string apellidos;
                int edad;
                int cantidas_de_calificaciones;
                float calificacion;
                float suma = 0;
                float promedio;
                float calificacion_mayor = 0;
                float calificacion_menor = 10;
                int aprobadas = 0;
                int reprobadas = 0;

                // ------------------ Para capturar los datos del alumno ------------------------------------

                cout << "\nNombre del alumno: ";
                cin >> nombres;

                cout << "Apellido del alumno: ";
                cin >> apellidos;

                cout << "Edad: ";
                cin >> edad;

                while (edad < 10 || edad > 100) {
                    cout << "La edad es invalida" << endl;
                    cout << "Ingrese la edad nuevamente: ";
                    cin >> edad;
                }

                // ------------------ Para capturar las calificaciones del alumno ------------------------------------

                cout << "Ingrese la cantidad de calificaciones: ";
                cin >> cantidas_de_calificaciones;

                if (cantidas_de_calificaciones <= 0) {
                    cout << "La cantidad de calificaciones debe ser mayor a cero." << endl;
                    break;
                }

                for (int i = 0; i < cantidas_de_calificaciones; i++) {

                    cout << "Ingrese la calificacion #" << (i + 1) << ": ";
                    cin >> calificacion;

                    while (calificacion < 0 || calificacion > 10) {

                        cout << "Calificacion invalida. Debe ser un numero entre 0 y 10." << endl;
                        cin >> calificacion;
                       
                    }

                    suma += calificacion;

                    // Contar aprobadas y reprobadas
                    if (calificacion < 6) {
                        reprobadas++;
                    } 
                    else {
                        aprobadas++;
                    }

                    // Encontrar calificacion mayor
                    if (calificacion > calificacion_mayor) {
                        calificacion_mayor = calificacion;
                    }

                    // Encontrar calificacion menor
                    if (calificacion < calificacion_menor) {
                        calificacion_menor = calificacion;
                    }
                }

                // ------------------ Para calcular el promedio de las calificaciones ------------------------------------

                promedio = suma / cantidas_de_calificaciones;

                cout << "\n===== RESUMEN =====" << endl;
                cout << "Estudiante: " << nombres << " " << apellidos << endl;
                cout << "Edad: " << edad << " años" << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Calificacion mas alta: " << calificacion_mayor << endl;
                cout << "Calificacion mas baja: " << calificacion_menor << endl;
                cout << "Calificaciones aprobatorias: " << aprobadas << endl;
                cout << "Calificaciones reprobatorias: " << reprobadas << endl;

                break;
            }

            case 2:

               cout << "\n=== INFORMACION DEL PROGRAMA ===" << endl;
                cout << "Este programa permite registrar los datos de un estudiante." << endl;
                cout << "Permite ingresar una cantidad variable de calificaciones," << endl;
                cout << "calcular el promedio, contar aprobadas y reprobadas," << endl;
                cout << "y encontrar la calificacion mas alta y mas baja." << endl;
                cout << "Las calificaciones de 6 a 10 se consideran aprobatorias." << endl;

                break;

            case 3:

                cout << "Saliendo del programa..." << endl;

                break;

            default:

                cout << "Opcion invalida, intente de nuevo." << endl;
        }

    } while(option != 3);

    return 0;
}
