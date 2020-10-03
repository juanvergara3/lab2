#include <iostream>
#include "Ejercicios.h"

using namespace std;

int main()
{
    short selec;

    // Ejercicio 1
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Ejercicio 2
    int  size;
    double suma, promedio;

    while(true){

        cout<<"\nIngrese el ejecicio a ejecutar: "; cin>>selec;
        cout<<endl;

        switch(selec){

        default:
            cout<<"Ejercicio no definido! "<<endl;
            break;

        case 1: // Ejercicio 1

            fun_b(array, 10);
            cout<<"Despues de ejecutar func_b:\n"<<endl;
            cout<<"* La direccion de memoria del array es "<<&array<<" y se usan 4 bytes para cada uno de sus elementos (40 bytes en total)"<<endl;
            cout<<"* array[3] = "<<array[3]<<" y su direccion es "<<&array[3]<<endl;
            cout<<"* La funcion fun_b invierte el orden de los elementos del array"<<endl;

            break;

        case 2: //Ejercicio 2

            cout<<"Ingrese el tamaño del array: "; cin>>size;

            double *array2 = new double[size]; //crear array de tamaño size

            for(int k = 0; k<=size-1; k++){ //ingresar datos al array
                cout<<"Ingrese el dato en la posicion "<<k<<": ";
                cin>>array2[k];
            }

            fun_c(array2, size, &promedio, &suma);

            delete[] array2; //borrar array despues de terminar

            cout<<"El promedio es: "<<promedio<<endl;
            cout<<"La suma es: "<<suma<<endl;

            break;




        }
    }
    return 0;
}
