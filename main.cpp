#include <iostream>
#include "Ejercicios.h"
#include "Problemas.h"

using namespace std;


//Ejercicios tinkercad
//https://www.tinkercad.com/things/7FrvmogmtUP

//Problemas tinkercad
//https://www.tinkercad.com/things/cdfRpy66VrY


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

    //Problema 3
    bool compare;

    //Problema 6
    char str[80]={};
    char num[80]={};

    //Problema 11
    char ref[15][20];
    char action;
    char i;
    short j, i_short;
    short position[2];

    //Problema 13
    char choice;

    //Problema 14
    short matrix_5x5[5][5];

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

            else cout<<"\nIngrese una cantidad positiva! "<<endl;

            break;
        }

        case 2:{ //Problema 2

            char *letter_array = new char[201]; // para tener en cuenta el \0

            rand_letter_array(letter_array);

            count_letter_array(letter_array);

            delete[] letter_array;
            break;
        }

        case 3:{ //Problema 3

            cout<<"Ingrese una palabra: ";cin>>str;
            cout<<"Ingrese otra palabra: ";cin>>num;

            compare = string_compare(str, num);

            if (compare == true) cout<<"Las cadenas son iguales"<<endl;
            else cout<<"Las cadenas son distintas"<<endl;

            break;
        }

        case 4:{ //Problema 4

            cout<<"Ingrese un numero: ";cin>>str;

            amount= str_to_int(str);
            cout<<str<<" ---> "<<amount<<endl;

            break;
        }

        case 5:{ //Problema 5

            cout<<"Ingrese un numero: ";cin>>amount;

            int_to_str(amount, str);
            cout<<amount<<" ---> "<<str<<endl;

            break;
        }

        case 6:{ //Problema 6

            cout<<"Ingrese una palabra: ";cin>>str;

            cout<<"\nOriginal: "<<str<<" ---> ";

            min_to_may(str);

            cout<<"En mayusculas: "<<str<<endl;

            break;
        }

        case 7:{ //Problema 7
            cout<<"Ingrese una palabra: ";cin>>str;

            cout<<"\nOriginal: "<<str<<" ---> ";

            delete_rep_letters(str);

            cout<<"Sin repetidos: "<<str<<endl;
            break;
        }

        case 8:{ //Problema 8
            cout<<"Ingrese una cadena de caracteres: ";cin>>str;

            cout<<"\nOriginal: "<<str<<" ---> ";

            separate_int_from_char(str, num);

            cout<<"Texto: "<<str<<" ; Numeros: "<<num<<endl;
            break;
        }

        case 9:{ //Problema 9

            while(true){
               cout<<"Ingrese el tamaño del arreglo: "; cin>>size;

               if(size>0) break;
               else cout<<"Ingrese un entero positivo!"<<endl;
            }

            int *array_p9 = new int[size];
            int *n = new int;

            for(int k = 0; k<size;k++){
                while(true){
                    cout<<"Ingrese el dato numero "<<k+1<<": "; cin>>array_p9[k];

                   if(array_p9[k] >= 0) break;
                   else cout<<"Ingrese un entero positivo!"<<endl;
                }
            }

            while(true){
               cout<<"Ingrese la cantidad de digitos con que desea partir el arreglo: "; cin>>*n;

               if(*n>0) break;
               else cout<<"Ingrese un entero positivo!"<<endl;
            }

            cout<<"\nPara el arreglo {";
            for(int k = 0; k<size; k++)
                cout<<(array_p9[k])<<' ';
            cout<<"\b}"<<endl;

            cout<<"n = "<<*n<<": suma = ";
            amount = separate_and_sum(*n, array_p9, size);
            cout<<amount<<endl;

            delete[] array_p9;
            delete n;

            break;
        }

        case 10:{ //Problema 10
            cout<<"Ingrese un numero romano: "; cin>>str;

            uppercase(str);

            compare = validate_rom(str);

            if(compare == true){

                cout<<"El numero ingresado fue: "<<str<<endl;
                rom_to_arab(str);
                cout<<"Que corresponde a: "<<str<<endl;
            }

            else cout<<"Entrada invalida!"<<endl;

            break;
        }

        case 11:{ //Problema 11

              generate_ref(ref);
              compare = true;

              while(compare){
                  cout<<"Ingrese 'r' para reservar, 'c' para cancelar, 'v' para visualizar y 's' para salir: ";cin>>action;

                  if(int(action) >= 65 && int(action) <= 90) action = char(int(action) + 32); //convierte action en minuscula

                  if(action == 'r' || action == 'c'){

                      cout<<"fila (A-O): ";cin>>i;
                      cout<<"columna (1-20): ";cin>>j;

                      i_short = short(i);

                      if( j>=1 && j<=20 && ((i_short>=65 && i_short <=79) || (i_short>=97 && i_short <=111)) ){
                        get_position(i, j, position);
                        action_ref(ref, position, action);
                      }
                      else cout<<"Entrada no valida!"<<endl;
                  }

                  else if (action == 'v') print_ref(ref);

                  else if (action == 's') compare = false;

                  else cout<<"Opcion no valida"<<endl;

              }
            break;
        }

        case 12:{ //Problema 12

            //ingresar el tamano de la matriz y llenarla 1 por 1

            cout<<"Ingrese el tamaño del cuadrado magico: "; cin>>size;

            if(size>0) {

                compare = majic_square_verify(size);

                if(compare == true) cout<<"Es un cuadrado magico!"<<endl;
                else cout<<"No es un cuadrado magico!"<<endl;

            }

            else cout<<"Ingrese un tamaño valido!"<<endl;

            break;
        }

        case 13:{//Problema 13

            cout<<"Ingrese 'm' para llenar la imagen manualmente, o 'd' para usar la imagen de demostracion por defecto (PDF): "; cin>>choice;

            amount =number_of_stars(choice);

            cout<<"\nCantidad de posibles estrellas: "<<amount<<endl;

            break;
        }

        case 14:{ //Problema 14

            cout<<"Original: "<<endl;
            fill_matrix(matrix_5x5);
            print_matrix(matrix_5x5);

            cout<<"90: "<<endl;
            rotate_matrix(matrix_5x5);
            print_matrix(matrix_5x5);
            cout<<endl;

            cout<<"180: "<<endl;
            rotate_matrix(matrix_5x5);
            print_matrix(matrix_5x5);
            cout<<endl;

            cout<<"270: "<<endl;
            rotate_matrix(matrix_5x5);
            print_matrix(matrix_5x5);
            cout<<endl;

            cout<<"360: "<<endl;
            rotate_matrix(matrix_5x5);
            print_matrix(matrix_5x5);
            cout<<endl;

            break;
        }

        case 15:{ //Problema 15

            //Algunas pruebas predefinidas y sus respectivos resultados esperados, para revisar con mayor facilidad

            //int r1[4] = {0, 0, 8, 4}, r2[4] = {5, 2, 6, 7}, res[4]; // 5 2 3 2
            //int r1[4] = {1, 1, 8, 4}, r2[4] = {4, 3, 2, 4}, res[4]; // 4 3 2 2
            //int r1[4] = {1, 1, 4, 2}, r2[4] = {2, 1, 1, 1}, res[4]; // 2 1 1 1
            //int r1[4] = {1, 1, 1, 1}, r2[4] = {2, 2, 1, 1}, res[4]; // 0 0 0 0
            //int r1[4] = {1, 1, 3, 1}, r2[4] = {3, 1, 3, 1}, res[4]; // 3 1 1 1
            //int r1[4] = {1, 0, 1, 2}, r2[4] = {1, 1, 1, 2}, res[4]; // 1 1 1 1
            //int r1[4] = {1, 1, 1, 1}, r2[4] = {1, 1, 1, 1}, res[4]; // 1 1 1 1
            //int r1[4] = {-4, -3, 3, 2}, r2[4] = {-2, -2, 2, 2}, res[4]; // -2 -2 1 1
            //int r1[4] = {-4, -3, 6, 4}, r2[4] = {1, -2, 3, 4}, res[4]; // 1 -2 1 3

            int r1[4] = {}, r2[4] = {}, res[4];

            cout<<"Ingrese los datos del primer rectangulo en orden:"<<endl; cin>>r1[0]>>r1[1]>>r1[2]>>r1[3];
            cout<<"Ingrese los datos del segundo rectangulo en orden:"<<endl; cin>>r2[0]>>r2[1]>>r2[2]>>r2[3];

            if(r1[2]>0 && r1[3]>0 && r2[2]>0 && r2[3]>0){

                calculate_rectangles_intersection(r1, r2, res);

                cout<<"La interseccion es: {";
                for(int k = 0; k<4; k++) cout<<res[k]<<", ";
                cout<<"\b\b}"<<endl;

            }
            else cout<<"Ingrese medidas validas!"<<endl;

            break;
        }

        case 16:{ //Problema 16

            cout<<"Ingrese el tamaño de la malla: "; cin>>size;

            if(size>0 && size<30){

                unsigned long long *result = new unsigned long long ;

                *result = travel_grid(size);

                cout<<"Para un malla de "<<size<<'x'<<size<<" hay "<<*result<<" caminos posibles"<<endl;

                delete result;

            }
            else cout<<"Ingrese un entero positivo (para valores cercanos y mayores que 30 los valores de desbordan y se obtienen resultados indeterminados)!"<<endl;

            break;
        }

        case 17:{ //Problema 17

            cout<<"Ingrese un numero: "; cin>>size;

            if(size > 0){

                suma = sum_friendly_smaller_than_n(size);
                cout<<"El resultado de la suma es: "<<suma<<endl;

            }
            else cout<<"Ingrese un numero positivo!"<<endl;

            break;
        }

        case 18:{ //Problema 18

            cout<<"Que permutacion desea ver?: "; cin>>size;

            if(size>0) n_permutation(size);

            else cout<<"Ingrese un entero positivo!"<<endl;

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
