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
void int_to_str(int number, char *str, int size){

    size-=2;

    if(number<0) {
        str[0] = '-';
        number *= -1;
    }

    for(;number>0;number /= 10, size--){

        str[size] = number%10 + '0';
    }
}
