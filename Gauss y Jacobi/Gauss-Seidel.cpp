#include <iostream>
#include <cmath>

using namespace std;
/*
*EDWIN ADONY MONTEJO MARTÍNEZ
*PROYECTO DE C++ QUE RESUELVE LAS ECUACIONES LINEALES CON EL MÉTODO DE GAUSS-SEIDEL
*
*Se trabaja una función llamada 'solveGausSeidel' para que retorne los datos de la solucion (todas las variables las suelo trabajar con camelCase para que se comprenda rápidamente)
*entre nuestras variables esta la variable size que contiene el rango de nuestra matriz
*nuestras variables A y b que contienen los valores de nuestra matriz A y matriz b siendo los valores y resultados y esta vez se le agrega el arreglo x que son los valores iniciales
*en nuestra función recibe ciertos parámetros siendo estos la matriz a, b y c, el tamaño o rago de nuestra matriz, un máximo de iteraciones y nuestra tolerancia
*/

void solveGaussSeidel(double** A, double* b, double* x, int size, int maxIterations, double tolerance) {
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

        for (int i = 0; i < size; i++) {
            x[i] = xNew[i];
        }

        iteration++;
    }

    if (iteration >= maxIterations) {
        cout << "El método de Gauss-Seidel no convergió en " << maxIterations << " iteraciones." << endl;
    } else {
        cout << "Solución encontrada en la iteración " << iteration << "." << endl;
    }

    delete[] xNew;
}

int main() {
    int size;

    cout << "Ingrese el tamaño de la matriz: ";
    cin >> size;

    // Crear la matriz A y el vector b usando arreglos dinámicos
    double** A = new double*[size];
    for (int i = 0; i < size; i++) {
        A[i] = new double[size];
    }

    double* b = new double[size];
    double* x = new double[size];

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

    cout << "Ingrese los valores iniciales del vector x:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> x[i];
    }

    // Resolver el sistema de ecuaciones usando el método de Gauss-Seidel
    solveGaussSeidel(A, b, x, size, 100, 0.0000000001);

    // Imprimir la solución
    cout << "Solución:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    // Liberar la memoria de los arreglos dinámicos
    for (int i = 0; i < size; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] x;

    return 0;
}

