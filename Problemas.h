#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace  std;

//Problema 1
void calculo_devuelta(int amount);

//Problema2
void rand_letter_array(char *letter_array);
void count_letter_array(char *letter_array);

//Problema 3
bool string_compare(char *str1, char *str2);

//Problema 4
int str_to_int(char *str);

//Problema 5
void int_to_str(int number, char *str);

//Problema 6
void min_to_may(char *str);

//Problema 7
int size_of_array(char *str);
void clone_array(char *str, char *res, int size = 0);
void delete_rep_letters(char *str);

//Problema 8
void separate_int_from_char(char *str, char *num);

//Problema 11
void generate_ref(char ref[15][20]);
void print_ref(char ref[15][20]);
void action_ref(char ref[15][20], short *position, char action);
void get_position(char i, short j, short *position);
