#include "Ejercicios.h"


//Ejercicio 1
void fun_a(int *px, int *py){
int tmp = *px;
*px = *py;
*py = tmp;
}

void fun_b(int a[], int tam){
int f, l;
int *b = a;
for (f = 0, l = tam -1; f < l; f++, l--) fun_a(&b[f], &b[l]);
}

//Ejercicio 2
void fun_c(double *a, int n, double *promedio, double *suma){
    *suma = 0.0;
    for (int i = 0; i < n; i++)
        *suma += a[i];
    *promedio = *suma / n;
}
