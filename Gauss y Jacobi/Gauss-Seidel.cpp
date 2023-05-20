#include <iostream>
#include <cmath>

using namespace std;
/*
*EDWIN ADONY MONTEJO MART�NEZ
*PROYECTO DE C++ QUE RESUELVE LAS ECUACIONES LINEALES CON EL M�TODO DE GAUSS-SEIDEL
*
*Se trabaja una funci�n llamada 'solveGausSeidel' para que retorne los datos de la solucion (todas las variables las suelo trabajar con camelCase para que se comprenda r�pidamente)
*entre nuestras variables esta la variable size que contiene el rango de nuestra matriz
*nuestras variables A y b que contienen los valores de nuestra matriz A y matriz b siendo los valores y resultados y esta vez se le agrega el arreglo x que son los valores iniciales
*en nuestra funci�n recibe ciertos par�metros siendo estos la matriz a, b y c, el tama�o o rago de nuestra matriz, un m�ximo de iteraciones y nuestra tolerancia
*/

void solveGaussSeidel(double** A, double* b, double* x, int size, int maxIterations, double tolerance) {
    double* xNew = new double[size];  // Vector de soluciones en la siguiente iteraci�n

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
        cout << "El m�todo de Gauss-Seidel no convergi� en " << maxIterations << " iteraciones." << endl;
    } else {
        cout << "Soluci�n encontrada en la iteraci�n " << iteration << "." << endl;
    }

    delete[] xNew;
}

int main() {
    int size;

    cout << "Ingrese el tama�o de la matriz: ";
    cin >> size;

    // Crear la matriz A y el vector b usando arreglos din�micos
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

    // Resolver el sistema de ecuaciones usando el m�todo de Gauss-Seidel
    solveGaussSeidel(A, b, x, size, 100, 0.0000000001);

    // Imprimir la soluci�n
    cout << "Soluci�n:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    // Liberar la memoria de los arreglos din�micos
    for (int i = 0; i < size; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] x;

    return 0;
}

