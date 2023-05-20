#include <iostream>
#include <cmath>
#include <String>

using namespace std;

/*
*EDWIN ADONY MONTEJO MARTÍNEZ
*PROYECTO DE C++ QUE RESUELVE LAS ECUACIONES LINEALES CON EL MÉTODO DE JACOBI
*
*Se trabaja una función llamada 'solveJacobi' para que retorne los datos de la solucion (todas las variables las suelo trabajar con camelCase para que se comprenda rápidamente)
*entre nuestras variables esta la variable size que contiene el rango de nuestra matriz
*nuestras variables A y b que contienen los valores de nuestra matriz A y matriz b siendo los valores y resultados
*en nuestra función recibe ciertos parámetros siendo estos la matriz a y b, el tamaño o rago de nuestra matriz, un máximo de iteraciones y nuestra tolerancia
*/

double* solveJacobi(double** A, double* b, int size, int maxIterations, double tolerance) {
    double* x = new double[size];  // Vector inicial de soluciones
    double* xNew = new double[size];  // Vector de soluciones en la siguiente iteración

    int iteration = 0;
    double error = tolerance + 1.0;

    while (iteration < maxIterations && error > tolerance) {
        for (int i = 0; i < size; i++) {
            double sum = 0.0;

            for (int j = 0; j < size; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }

            xNew[i] = (b[i] - sum) / A[i][i];
        }

        error = 0.0;
        for (int i = 0; i < size; i++) {
            double diff = abs(xNew[i] - x[i]);
            if (diff > error) {
                error = diff;
            }
        }

        double* temp = x;
        x = xNew;
        xNew = temp;

        iteration++;
    }

    if (iteration >= maxIterations) {
        cout << "El método de Jacobi no convergió en " << maxIterations << " iteraciones." << endl;
    } else {
        cout << "Solución encontrada en la iteración " << iteration << "." << endl;
    }

    delete[] xNew;

    return x;
}

int main() {
    int size;

    cout << "Ingrese el tamaño de la matriz: ";
    cin >> size;

    // Crear la matriz A y el vector b usando arreglos
    double** A = new double*[size];
    for (int i = 0; i < size; i++) {
        A[i] = new double[size];
    }

    double* b = new double[size];

    cout << "Ingrese los coeficientes de la matriz A:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Ingrese los valores del vector b:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> b[i];
    }

    // Resolver el sistema de ecuaciones usando el método de Jacobi
    double* solution = solveJacobi(A, b, size, 100, 0.0000000001);

    // Imprimir la solución
    cout << "Solución:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "x[" << i << "] = " << solution[i] << endl;
    }

    // Liberar la memoria de los arreglos dinámicos
    for (int i = 0; i < size; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] solution;

    return 0;
}

