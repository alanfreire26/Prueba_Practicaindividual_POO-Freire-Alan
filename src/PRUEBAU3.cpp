
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    

    string estudiantes[39] = {
        "Acosta Hanna", "Andrade Hugo", "Atiencia Josue", "Balarrezo Diego",
        "Barrionuevo Job", "Bedoya Juan", "Bravo Samuel", "Cajiao Paulo",
        "Calvopina Brandon", "Castelo Katherine", "Chacha Victor", "Chiluiza Steed",
        "Dominguez Daniel", "Freire Alan", "Gualle Abisag", "Guaman Alexander",
        "Guanga Sebastian", "Guanotoa Karla", "Landeta Edison", "Lara Karen",
        "Loor Jhon", "Lopez Washington", "Miranda Imanol", "Monar Jhair",
        "Muyulema Mateo", "Narvaez Antonella", "Nunez Bryan", "Pilco Mario",
        "Pomaquero Katherine", "Quevedo Gina", "Rivadeneira Matias", "Rocha Carolina",
        "Sanchez Isaac", "Segovia Joseph", "Supe Joan", "Toapanta Matias",
        "Verdesoto Kevin", "Villacres Alejandro", "Viteri Shantal"
    };

    double notas[39][5] = {0};
    double promedio[39] = {0};

    int opcion;


    do {

        cout << "\n========================================" << endl;
        cout << " UNIVERSIDAD TECNICA DE AMBATO" << endl;
        cout << " SISTEMA DE REGISTRO DE NOTAS" << endl;
        cout << "========================================" << endl;

        cout << "\n1. Operaciones basicas" << endl;
        cout << "2. Registrar notas" << endl;
        cout << "3. Guardar resultados en TXT" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

       

        if(opcion == 1) {

            double num1, num2;
            int operacion;

            cout << "\n===== OPERACIONES BASICAS =====" << endl;

            cout << "Ingrese el primer numero: ";
            cin >> num1;

            cout << "Ingrese el segundo numero: ";
            cin >> num2;

            cout << "\n1. Suma" << endl;
            cout << "2. Resta" << endl;
            cout << "3. Multiplicacion" << endl;
            cout << "4. Division" << endl;
            cout << "Seleccione una operacion: ";
            cin >> operacion;

            switch(operacion) {
                case 1:
                    cout << "Resultado: " << num1 + num2 << endl;
                    break;

                case 2:
                    cout << "Resultado: " << num1 - num2 << endl;
                    break;

                case 3:
                    cout << "Resultado: " << num1 * num2 << endl;
                    break;

                case 4:
                    if(num2 != 0) {
                        cout << "Resultado: " << num1 / num2 << endl;
                    }
                    else {
                        cout << "Error: No se puede dividir para cero" << endl;
                    }
                    break;

                default:
                    cout << "Operacion invalida" << endl;
            }
        }

        // ==========================================
        // OPCION 2 - REGISTRO DE NOTAS
        // ==========================================

        else if(opcion == 2) {

            for(int i = 0; i < 39; i++) {

                double suma = 0;
                double mayor = 0;
                double menor = 0;
                int aprobadas = 0;
                int reprobadas = 0;

                cout << "\n========================================" << endl;
                cout << "Estudiante: " << estudiantes[i] << endl;
                cout << "========================================" << endl;

                for(int j = 0; j < 5; j++) {

                    cout << "Ingrese la nota " << j + 1 << ": ";
                    cin >> notas[i][j];

                    suma += notas[i][j];

                    if(j == 0) {
                        mayor = notas[i][j];
                        menor = notas[i][j];
                    }
                    else {

                        if(notas[i][j] > mayor) {
                            mayor = notas[i][j];
                        }

                        if(notas[i][j] < menor) {
                            menor = notas[i][j];
                        }
                    }

                    if(notas[i][j] >= 7) {
                        aprobadas++;
                    }
                    else {
                        reprobadas++;
                    }
                }

                promedio[i] = suma / 5;

                cout << "\n===== RESULTADOS =====" << endl;

                for(int j = 0; j < 5; j++) {
                    cout << "Nota " << j + 1 << ": " << notas[i][j] << endl;
                }

                cout << "Promedio final: " << promedio[i] << endl;
                cout << "Nota mayor: " << mayor << endl;
                cout << "Nota menor: " << menor << endl;
                cout << "Aprobadas: " << aprobadas << endl;
                cout << "Reprobadas: " << reprobadas << endl;

                if(promedio[i] >= 7) {
                    cout << "Estado final: APROBADO" << endl;
                }
                else {
                    cout << "Estado final: REPROBADO" << endl;
                }
            }
        }

        // ==========================================
        // OPCION 3 - GUARDAR TXT
        // ==========================================

        else if(opcion == 3) {

            ofstream archivo("resultados.txt");

            for(int i = 0; i < 39; i++) {

                archivo << "========================================" << endl;
                archivo << "UNIVERSIDAD TECNICA DE AMBATO" << endl;
                archivo << "REGISTRO DE CALIFICACIONES" << endl;
                archivo << "========================================" << endl;

                archivo << "Nombre: " << estudiantes[i] << endl;

                for(int j = 0; j < 5; j++) {
                    archivo << "Nota " << j + 1 << ": " << notas[i][j] << endl;
                }

                archivo << "Promedio final: " << promedio[i] << endl;

                if(promedio[i] >= 7) {
                    archivo << "Estado final: APROBADO" << endl;
                }
                else {
                    archivo << "Estado final: REPROBADO" << endl;
                }

                archivo << "========================================" << endl << endl;
            }

            archivo.close();

            cout << "\nResultados guardados correctamente en resultados.txt" << endl;
        }


        else if(opcion == 4) {
            cout << "\nSaliendo del programa..." << endl;
        }

        else {
            cout << "\nOpcion invalida" << endl;
        }

    } while(opcion != 4);

    return 0;
}