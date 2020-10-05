#include "Problemas.h"

//Problema 1
void calculo_devuelta(int amount){

int devueltas[10] ={50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};

for(int k = 0; k<10; k++){
    cout<<devueltas[k]<<": "<<amount/devueltas[k]<<endl;
    amount %= devueltas[k];
}
cout<<"Faltante: "<<amount<<endl;

}

//Problema 2
void rand_letter_array(char *letter_array){

    srand (time(NULL));

    short num;

    for(int k = 0; k<201; k++){ //genera el array

        num = 65 +  rand() % (90 - 65 + 1);

        letter_array[k] = char(num);
        cout<<letter_array[k]<<' ';

    }
    cout<<"\n"<<endl;
}

void count_letter_array(char *letter_array){


    for(short letter = 65, count = 0; letter<=90; letter++){

        for(short k = 0; k<201; k++){

            if(letter_array[k] == char(letter)) count++;

        }
        cout<<char(letter)<<": "<<count<<endl;
        count = 0;


    }

}

//Problema 3
bool string_compare(char *str1, char *str2){

    int size1, size2;

    size1 = size_of_array(str1);
    size2 = size_of_array(str2);

    if(size1 == size2){

        for(int k = 0; k<= size1; k++) if(str1[k] != str2[k]) return false; //si alguno de sus elementos no es igual

        return true; //si todos son iguales
    }
    else return false; //si no son de igual tamaño
}

//Problema 4
int str_to_int(char *str){

    int result, i = 0, sign = 1;

    if(*str == '-') {
      sign = -1;
      i = 1;
    }

    for (; str[i]  != '\0'; ++i) result = result * 10 + str[i] - '0';

    return  result*sign;
}

//Problema 5
void int_to_str(int number, char *str){

    int size = 0, aux;

    if(number<0) { //si es negativo
        str[0] = '-';
        number *= -1;
        size++;
    }

    aux = number;

    while(aux>0){ //calcula el tamaño del numero
        aux /= 10;
        size++;
    }

    for(size-- ;number>0; number /= 10, size--) str[size] = number%10 + '0';
}

//Problema 6
void min_to_may(char *str){

    int aux;

    for(int k = 0; str[k] != '\0'; k++){

        aux = int(str[k]); //toma el valor ascii del caracter

        if(aux>=97 && aux<=122) str[k] = aux-32; //si pertenece a minusculas lo vuelve mayuscula

    }
}

//Problema 7
int size_of_array(char *str){

    int size = 0;

    for(int k = 0;;k++){ // calcula el tamaño del arreglo str

        if(str[k] != '\0') size++;
        else{
            size++;
            break;
        }
    }
    return size;
}

void clone_array(char *str, char *res, int size){

    if(size==0) size = size_of_array(str);

    if(res[0] == '\0') str[0] = '\0'; // si res esta vacio

    else{
        for(int k = 0; ; k++){ //clona el arreglo res en el arreglo str

            str[k] = res[k];

            if(res[k]=='\0'){
                str[k] = '\0';
                break;
            }
        }
    }


}

void delete_rep_letters(char *str){

    int count = 0, res_index = 0, size;
    char temp;

    size = size_of_array(str);

    char *res = new char[size]; //define res del mismo tamaño que str

    for (int k = 0; ; k++){ //recorre str

        if(str[k] == '\0') break; // rompe el ciclo y marca la posicion del \0

        temp = str[k]; //toma el caracter actual de str

        for(int w = 0; ; w++){ //recorre res

            if(res[w] == '\0') break; //rompe cuando llega a \0

            if(temp == res[w]) count++; //si esta repetido lo cuenta

        }

        if(count == 0) { //si no esta repetido lo agrega
            res[res_index] = temp;
            res[res_index+1] = '\0';
            res_index++;
        }

        else count = 0; //si esta repetido reseta el contador
    }//final del for que recorre str

    clone_array(str, res, size);

delete[]res;
}

//Problema 8
void separate_int_from_char(char *str, char *num){
/*str tiene numeros y letras. Despues de ejecutada str tiene solo letras y num solo numeros.
NOTA: tanto str como num son arrays de char*/

    int num_index = 0, size, res_index = 0;
    char temp;

    size = size_of_array(str);

     char *res = new char[size]; //define res del mismo tamaño que str

    for(int k = 0 ;; k++){ //recorre str

        if(str[k] == '\0') break;

        temp = str[k];

        if (int(temp)<=57 && int(temp)>=48){ // si es un numero va a num
            num[num_index] = temp;
            num_index++;
        }

        else{ //si no es un numero va a res
            res[res_index] = temp;
            res_index++;
        }
    }

    res[res_index] = '\0';
    num[num_index] = '\0';

    if(res_index == 0) res[0] = '\0';

    clone_array(str, res, size);

    delete[]res;
}

//Problema 11
void get_position(char i, short j, short *position){

    position[1] = j - 1;

    if(int(i)>=97 && int(i)<=111) i = int(i) - 32;

    position[0] = i - 65;

}

void action_ref(char ref[15][20], short *position, char action){

    short i = position[0], j = position[1];

    if(action == 'c') {
        if(ref[i][j] == '+') {
          ref[i][j] = '-';
          cout<<"Cancelado correctamente"<<endl;
        }
        else cout<<"El asiento ya esta vacio!"<<endl;

    }
    else if (action == 'r') {
        if(ref[i][j] == '-') {
          ref[i][j] = '+';
          cout<<"Reservado correctamente"<<endl;
        }
        else cout<<"El asiento ya esta reservado!"<<endl;
    }
}

void generate_ref(char ref[15][20]){

    for(int i = 0; i<15; i++){ //recorre filas

        for(int j = 0; j<20; j++){ //recorre columnas

            ref[i][j] = '-';

        }

    }
}

void print_ref(char ref[15][20]){

    for(int i = 0; i<15; i++){ //recorre filas

        for(int j = 0; j<20; j++){ //recorre columnas

            cout<<ref[i][j]<<' ';

        }
    cout<<endl;
    }
}
