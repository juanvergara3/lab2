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

void llenar_array_double(double *array, int size){

    char c;

    cout<<"Ingrese 'm' para llenado manual o 'a' para llenado aleatorio: "; cin>>c;

    if(c=='m' || c=='M'){
        for(int k = 0; k<=size-1; k++){ //ingresar datos manualmente al array
                cout<<"Ingrese el dato en la posicion "<<k<<": ";
                cin>>array[k];
            }
    }

    else if (c=='a' || c=='A'){

        srand (time(NULL));

        for(int k = 0; k<=size-1; k++) array[k] = rand() % -1000 +1000; //llena el array con numeros aleatorios

    }
    else cout<<"Entrada invalida!"<<endl;
}
