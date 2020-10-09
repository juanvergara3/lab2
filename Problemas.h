#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <bits/stdc++.h>
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

//Problema 9
int separate_and_sum(int n, int *array, int length);

//Problema 10
void rom_to_arab(char *str);
bool validate_rom(char*str);
void uppercase(char *str);
int count_digit(int number);

//Problema 11
void generate_ref(char ref[15][20]);
void print_ref(char ref[15][20]);
void action_ref(char ref[15][20], short *position, char action);
void get_position(char i, short j, short *position);

//Problema 14
void fill_matrix(short matrix[5][5]);
void rotate_matrix(short matrix[5][5]);
void print_matrix(short matrix[5][5]);

//Problema 15
void calculate_rectangles_intersection(int *r1, int *r2, int *res);
void lower_right_corner(int *r, int *corner);
int max(int *x);
void draw_rectangle(int *r, int **plano, short fill);
void fill_plane(int **plano, int x_max, int y_max);
void calculate_intersection(int **plano, int x_max, int y_max, int *res, short fill);

//Problema 16
unsigned long long travel_grid(int);
unsigned long long comb(int, int);

//Problema 17
int get_divisores_sum(int);
double sum_friendly_smaller_than_n(int);
