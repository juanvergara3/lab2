#include <iostream>
#include "Ejercicios.h"
#include "Problemas.h"

using namespace std;

int main()
{
    short selec;
    bool loop = true;

    // Ejercicio 1
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Ejercicio 2
    int  size;
    double suma, promedio;

    //Ejercicio 3
    unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};

    //Problema 1, 4 y 5
    int amount;

    while(loop){ //while ejercicios

        cout<<"\nIngrese el ejecicio a ejecutar (-1 para ir a los problemas): "; cin>>selec;
        cout<<endl;

        switch(selec){//switch ejercicios

        default:{
            cout<<"Ejercicio no definido! "<<endl;
            break;
        }

        case 1:{ // Ejercicio 1

            fun_b(array, 10);
            cout<<"Despues de ejecutar func_b:\n"<<endl;
            cout<<"* La direccion de memoria del array es "<<&array<<" y se usan 4 bytes para cada uno de sus elementos (40 bytes en total)"<<endl;
            cout<<"* array[3] = "<<array[3]<<" y su direccion es "<<&array[3]<<endl;
            cout<<"* La funcion fun_b invierte el orden de los elementos del array"<<endl;

            break;
        }

        case 2: {//Ejercicio 2

            cout<<"Ingrese el tamaño del array: "; cin>>size;

            if(size>0){
                double *array2 = new double[size]; //crear array de tamaño size

                llenar_array_double(array2, size); //funcion que llena el array con datos

                fun_c(array2, size, &promedio, &suma);

                delete[] array2; //borrar array despues de terminar

                cout<<"El promedio es: "<<promedio<<endl;
                cout<<"La suma es: "<<suma<<endl;

            }


            break;
        }

        case 3:{//Ejercicio 3

            cout<<" b = "<<b<<" (Direccion de memoria del primer arreglo de b (Primer elemento de dicho arreglo))"<<endl;

            cout<<" b+2 = "<<b+2<<" (Direccion de memoria del tercer arreglo de b (Primer elemento de dicho arreglo))"<<endl;

            cout<<" *(b+2) = "<<*(b+2)<<" (Direccion de memoria del primer elemento del tercer arreglo de b (Direccion de dicho arreglo))"<<endl;

            cout<<" *(b+2)+1 = "<<*(b+2)+1<<" (Direccion de memoria del segundo elemento del tercer arreglo de b)"<<endl;

            cout<<" *(*(b+2)+1) = "<<*(*(b+2)+1)<<" (Segundo elemento del tercer arreglo de b)"<<endl;

            cout<<" b[3][1] = "<<b[3][1]<<" (Segundo elemento del cuarto arreglo de b)"<<endl;

            cout<<" *b++ = "<<*(*(b+1))<<" (No se puede incrementar con el operador '++', pero si con '+1', en cuyo caso seria la direccion del segundo arreglo de b(Primer elemento de dicho arreglo))"<<endl;

            break;
        }

        case -1:{  //salida del ciclo
            loop = false;
                    break;
        }

        }//fin switch ejercicios
    }//fin while ejercicios

    loop = true; //reincia el ciclo

    while(loop){//while problemas

        cout<<"\nIngrese el problema a ejecutar (-1 para salir): "; cin>>selec;
        cout<<endl;

        switch(selec){//switch problemas

        default:{
            cout<<"Problema no definido! "<<endl;
            break;
        }

        case 1:{ //Problema 1
            cout<<"Ingrese la cantidad de dinero: "; cin>>amount;

            if (amount>=0) calculo_devuelta(amount);

            else cout<<"Ingrese una cantidad positiva! "<<endl;

            break;
        }

        case 2:{ //Problema 2

            char *letter_array = new char[201]; // para tener en cuenta el \0

            rand_letter_array(letter_array);

            count_letter_array(letter_array);

            delete[] letter_array;
            break;
        }

        case 3:{ //Problema 3***

            break;
        }

        case 4:{ //Problema 4

            char* str = new char[5]{'1', '2', '3', '4', '5'};

            amount= str_to_int(str);
            cout<<str<<" ---> "<<amount<<endl;

            str[0] = '-';
            amount= str_to_int(str);
            cout<<str<<" ---> "<<amount<<endl;

            delete[] str;

            break;
        }

        case 5:{ //Problema 5

            char* str = new char[7]; //se tiene en cuenta el \0

            amount = -12345;
            int_to_str(amount, str, 7);
            cout<<amount<<" ---> "<<str<<endl;

            amount = 123456;
            int_to_str(amount, str, 7);
            cout<<amount<<" ---> "<<str<<endl;

            delete[] str;

            break;
        }

        case -1:{ //salida del programa
            loop = false;
                    break;
        }

        }//fin switch problemas
    }//fin while problemas
    return 0;
}
