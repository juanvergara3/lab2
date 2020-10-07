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

//Problema 9
int separate_and_sum(int n, int *array, int length){


    int count = 1, min = length - n - 1, max, copy_index = 0, copy_size = length;
    int potencia = pow(10, n-1), sum = 0, number = 0; //calcula el numero por el que hay que multiplicar cada digito


    if(length%n != 0){ //si el array no se puede partir en numeros de n digitos

        while((copy_size+copy_index)%n != 0) copy_index++; //define el indice en que empieza la copia

        copy_size = length+copy_index; //y el tamaño de copy

    }

    int *copy = new int[copy_size]; //crea el arreglo en que se va a clonar array

    if(length != copy_size)  for(int i = 0; i < copy_index; i++) copy[i] = 0; //pone 0's al principio si clone y array no son de igual tamaño

    for(int i = 0, j = copy_index; i <= length; i++, j++) copy[j] = array[i]; //clona el array

    length = copy_size - 1;
    max = length;

    for(; length > -1; length--, count++){ //recorre copy desde el final hasta el principio

        if(count == n){ //cuando pasan n digitos

            min = length;

            for(int w = min, aux = potencia; w<= max; w++, aux /= 10){

                number +=copy[w]*aux;

            }

            count = 0;
            sum += number;
            number = 0;
            max = length; //redefine el indice maximo
        }


    }
    delete[] copy;
    return sum;
}

//Problema 10
void rom_to_arab(char *str){

    int size = size_of_array(str), res = 0;

    size--;

    short normalized[size], current, next;

    char temp_char;

    //Normalizacion:
    for(int k = 0; k<size; k++){ //convierte str cada letra de str a su equivalente decimal, en un arreglo de int (lo "normaliza")

        temp_char = str[k];

        switch (temp_char) {
        case 'M':{
            normalized[k] = 1000;
            break;
        }
        case 'D':{
            normalized[k] = 500;
            break;
        }
        case 'C':{
            normalized[k] = 100;
            break;
        }
        case 'L':{
            normalized[k] = 50;
            break;
        }case 'X':{
            normalized[k] = 10;
            break;
        }
        case 'V':{
            normalized[k] = 5;
            break;
        }
        case 'I':{
            normalized[k] = 1;
            break;
        }
        } //final switch
    } //final for de "normalizacion"


    //Transformacion numerica
    for(int k = 0; k<size; k++){ //usa las reglas de los numeros romanos y genera el numero en un int

        current = normalized[k];

        if(k != size - 1){ //reglas de numeros romanos

             next = normalized[k+1];

            if( next <= current) res += current;

            else res -= current;
        }

        else{ //para el ultimo numero que siempre se suma

           res += current;

        }
    }

    //conversion int ---> char[]
    int_to_str(res, str);

    size = count_digit(res);

    str[size] = '\0';

}

bool validate_rom(char*str){

    int size = size_of_array(str);

    for(int k = 0; k<size - 1; k++){

        if(str[k] != 'M' && str[k] != 'D' && str[k] != 'C' && str[k] != 'L' && str[k] != 'X' && str[k] != 'V' && str[k] != 'I'){
            return false;
        }
    }
    return true;
}

void uppercase(char *str){

    int size = size_of_array(str);
    short temp;

    for(int k = 0; k<size; k++){

        temp = short(str[k]);

        if(temp>=97 && temp<=122) str[k] = char(temp - 32);

    }

}

int count_digit(int n){
    int count = 0;
        while (n != 0) {
            n = n / 10;
            ++count;
        }
        return count;
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

//Problema 14
void fill_matrix(short matrix[5][5]){

    short filler = 1;

    for(int i = 0; i<5; i++){ //recorre filas

        for(int j = 0; j<5; j++, filler++){ //recorre columnas

          matrix[i][j] = filler;

        }
    }
}

void rotate_matrix(short matrix[5][5]){

    int** matrix_copy = new int*[5];
    for (int i = 0; i < 5; ++i) matrix_copy[i] = new int[5]; //crear array para la copia

    for(int i = 0; i<5; i++){

        for(int j = 0; j<5; j++){

            matrix_copy[i][j] = matrix[i][j]; // hace una copia de la matriz riginal

        }
    }

    int i_copy = 4, j_copy = 0;

    for(int i = 0; i<5; i++, j_copy++){ //recorre filas



        for(int j = 0; j<5; j++, i_copy--){ //recorre columnas

            matrix[i][j] = matrix_copy[i_copy][j_copy]; //rota la matriz

        }
        i_copy = 4;
    }

    for(int i = 0; i < 5; ++i) delete[] matrix_copy[i]; //borrar array para de la copia
    delete[] matrix_copy;
}

void print_matrix(short matrix[5][5]){

    short fill;

    for(int i = 0; i<5; i++){ //recorre filas

        for(int j = 0; j<5; j++){ //recorre columnas

            fill = matrix[i][j];

            if(fill<10) cout<<fill<<"  ";
            else cout<<fill<<' ';

        }
        cout<<endl;
    }
}
























