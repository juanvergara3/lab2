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

    int result, index = 0, sign = 1;

    if(str[0] == '-') {
      sign = -1;
      index = 1;
    }

    for (; str[index]  != '\0'; ++index)
        result = result * 10 + str[index] - '0';

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

    for(size-- ;number>0; number /= 10, size--)
        str[size] = number%10 + '0';
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

    for(int k = 0;;k++){ // calcula el tamaño del arreglo de caracteres str

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
        for(int k = 0; ; k++){ // clona el arreglo res en el arreglo str

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

    int num_index = 0, res_index = 0, size;
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

    clone_array(str, res, size);

    delete[]res;
}

//Problema 9
int separate_and_sum(int n, int *array, int length){

    int count = 1, min = length - n - 1, max, copy_index = 0, copy_size = length;
    int potencia = pow(10, n-1), sum = 0, number = 0; //calcula el numero por el que hay que multiplicar cada digito (pow)

    if(length%n != 0){ //si el array no se puede partir en numeros de n digitos

        while((copy_size+copy_index)%n != 0) copy_index++; //define el indice en que empieza la copia

        copy_size = length+copy_index; //y el tamaño de copy

    }

    int *copy = new int[copy_size]; //crea el arreglo en que se va a clonar array

    if(length != copy_size)  for(int i = 0; i < copy_index; i++) copy[i] = 0; //pone 0's al principio si copy y array no son de igual tamaño

    for(int i = 0, j = copy_index; i < length; i++, j++) copy[j] = array[i]; //clona el array

    length = copy_size - 1;
    max = length;

    for(; length > -1; length--, count++){ //recorre copy desde el final hasta el principio

        if(count == n){ //cuando pasan n digitos

            min = length;

            for(int w = min, aux = potencia; w<= max; w++, aux /= 10){ //crea numeros de n digitos

                number += copy[w]*aux;

            }
            count = 0;
            sum += number; //va sumando los numeros
            number = 0;
            max = length;
        }
    }

    delete[] copy;
    return sum;
}

//Problema 10
void rom_to_arab(char *str){

    int size = size_of_array(str), res = 0;

    size--; // "descarta" la posicion del \0

    short normalized[size], current, next;

    char temp_char;

    //Normalizacion:
    for(int k = 0; k<size; k++){ //convierte cada letra de str a su equivalente decimal, en un arreglo de short (lo "normaliza")

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
    } //final del for de "normalizacion"


    //Transformacion numerica:
    for(int k = 0; k<size; k++){ //usa las reglas de los numeros romanos y genera el numero en un int

        current = normalized[k];

        if(k != size - 1){ // para todos lo numeros excepto el ultimo

            next = normalized[k+1];

            if( next <= current ) res += current; //reglas de numeros romanos

            else res -= current;

        }

        else{ //para el ultimo numero que siempre se suma
           res += current;
        }
    }

    //conversion int ---> char[]:
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

            ref[i][j] = '-'; //definie todas las sillas vacias por defecto

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

//Problema 12
bool majic_square_verify(int size){

    bool fil =  false, col = false, diag = false, rep = false;
    int sum;

    int** square = new int*[size]; // crea el cuadrado
    for(int i = 0; i < size; ++i)
        square[i] = new int[size];

    fill_majic_square(size, square);

    sum = get_constant(square, size);

    rep = verify_no_repetition(square, size);

    if(rep == true){
        col = verify_col(square, size, sum);
        fil = verify_fil(square, size, sum);
        diag = verify_diag(square, size, sum);
    }

    for(int i = 0; i < size; ++i) { // borrar el cuadrado
        delete[] square[i];
    }
    delete[] square;

    if(col == true && fil == true && diag == true && rep == true) return true;
    else return false;
}

void fill_majic_square(int size, int **square){

    for(int i = 0; i<size; i++){

        for(int j = 0; j<size; j++){

            cout<<"Ingrese el elemento "<<i<<", "<<j<<": "; cin>>square[i][j];

        }
    }
}

bool verify_col(int **square, int size, int sum){

    int temp = 0;

    for(int j = 0; j<size; j++){
        for(int i = 0; i<size; i++){

            temp += square[i][j];

        }
        if(temp == sum) temp = 0;
        else return false;
    }
    return true;
}

bool verify_fil(int **square, int size, int sum){

    int temp = 0;

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){

            temp += square[i][j];

        }
        if(temp == sum) temp = 0;
        else return false;
    }
    return true;
}

bool verify_diag(int **square, int size, int sum){

    int temp = 0;

    for(int i = 0; i<size; i++) temp += square[i][size - i -1]; //diagional principal

    if(temp == sum) temp = 0;
    else return false;

    for(int i = 0; i<size; i++) temp += square[i][size - i -1]; //otra diagonal

    if(temp != sum) return false;

    return true;
}

int get_constant(int **square, int size){

    int sum = 0;

    for(int k = 0; k<size; k++) sum += square[k][0];

    return sum;
}

bool verify_no_repetition(int **square, int size){

    int temp[size*size], index = 0;

    for(int i = 0; i<size; i++){ //convertir al cuadrado en una tira (arreglo unidimensional)
        for(int j = 0; j<size; j++){

            temp[index] = square[i][j];
            index++;

        }
    }

    for (int i = 0; i < size - 1; i++) { //verificar si hay repetidos

        for (int j = i + 1; j < size; j++) {

            if (temp[i] == temp[j]) return false;

        }
    }
    return true;
}

//Problema 13
int number_of_stars(char choice){

    int size_i = 6, size_j = 8, count = 0;

    if(choice == 'm' || choice == 'M'){ //para el llenado manual de la imagen
        cout<<"Ingrese el alto de la imagen en pixeles: "; cin>>size_i;
        cout<<"Ingrese el ancho de la imagen en pixeles: "; cin>>size_j;
    }

    if(size_i>0 && size_j>0){

        int** picture= new int*[size_i]; // crea el cuadrado
        for(int i = 0; i < size_i; ++i)
            picture[i] = new int[size_j];

        if(choice == 'm' || choice == 'M')  fill_picture(picture, size_i, size_j);

        else if (choice == 'd' || choice == 'D'){ //Modo de demostracion
            int array[48] = {0, 3, 4, 0, 0, 0, 6, 8,
                                     5, 13, 6, 0, 0, 0, 2, 3,
                                     2, 6, 2, 7, 3, 0, 10, 0,
                                     0, 0, 4, 15, 4, 1, 6, 0,
                                     0, 0, 7, 12, 6, 9, 10, 4,
                                     5, 0, 6, 10, 6, 4, 8, 0};

            for(int i = 0, index = 0; i<size_i; i++){ //recrea la imagen que aparece en el pdf
                for(int j = 0; j<size_j; j++, index++){

                    picture[i][j] = array[index];

                }
            }
        }

        else{
            cout<<"Opcion invalida!"<<endl;
            return 0;
        }

        for(int i = 1; i<size_i - 1; i++){ //cuenta las estrellas

            for(int j = 1; j<size_j - 1; j++){

                if((picture[i][j]+picture[i][j-1]+picture[i][j+1]+picture[i-1][j]+picture[i+1][j])/5 > 6){

                    count++;

                }
            }
        }

        for(int i = 0; i < size_i; ++i) delete[]  picture[i]; //borrar la imagen
        delete[]  picture;
    }

    else cout<<"Tamaño invalido!"<<endl;

    return count;
}

void fill_picture(int **picture, int size_i, int size_j){

    for(int i = 0; i<size_i; i++){
        for(int j = 0; j<size_j; j++){

            cout<<"Ingrese el pixel ("<<i<<','<<j<<"): "; cin>>picture[i][j];

        }
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

    for(int i = 0; i < 5; ++i) delete[] matrix_copy[i]; //borrar array de la copia
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

//Problema 15
void calculate_rectangles_intersection(int *r1, int *r2, int *res){

    int traslation_x = 0, traslation_y = 0; // hay  que cambiar las traslaciones si alguna coordenada es menor que 0

    if(r1[0]<0 || r2[0]<0){ //traslacion en x

        if(r1[0]<r2[0]) traslation_x = abs(r1[0]);
        else traslation_x = abs(r2[0]);

    }

    if(r1[1]<0 || r2[1]<0){ //traslacion en y

        if(r1[1]<r2[1]) traslation_y = abs(r1[1]);
        else traslation_y = abs(r2[1]);

    }

    //Aplicar las traslaciones
    r1[0] += traslation_x;
    r2[0] += traslation_x;

    r1[1] += traslation_y;
    r2[1] += traslation_y;

    int c1[2], c2[2];
    lower_right_corner(r1, c1); // se encuentran las esquinas inferiores derechas de los rectangulos
    lower_right_corner(r2, c2);

    short fill =1;

    int xes[4] = {r1[0], r2[0], c1[0], c2[0]}, ys[4] ={r1[1], r2[1], c1[1], c2[1]}; // se crean arreglos con todas las x y todas las y

    int x_max = max(xes), y_max = max(ys); // se haya la maxima x y la maxima y

    int **plano; //se crea un plano en el que caben ambos rectangulos
    plano = new int *[y_max];
    for(int i = 0; i <y_max; i++)
    plano[i] = new int[x_max];

    fill_plane(plano, x_max, y_max);

    draw_rectangle(r1, plano, fill);
    draw_rectangle(r2, plano, fill+1);

    /* //Imprime el plano para referencia
    for(int i = 0; i<y_max; i++){
        for(int j = 0; j<x_max; j++){
          cout<<plano[i][j]<<' ';
        }
        cout<<endl;
    }*/

    calculate_intersection(plano, x_max, y_max, res, fill);

    //Desaplicar las traslaciones
    res[0] -= traslation_x;
    res[1] -= traslation_y;

        for(int i = 0; i < y_max; ++i) { //borrar el plano
            delete[] plano[i];
        }
        delete[] plano;
}

void lower_right_corner(int *r, int *corner){

    corner[0] = r[0] + r[2];
    corner[1] = r[1] + r[3];

}

int max(int *x){

    int big = x[0];

    for(int i = 1; i < 4; i++){

        if(x[i]>big) big = x[i];

    }
    return big;
}

void draw_rectangle(int *r, int **plano, short fill){

    for(int i = r[0]; i<r[0]+r[2]; i++){

        for(int j = r[1]; j<r[1]+r[3]; j++){

          if(plano[j][i] != 0) plano[j][i] = fill+1;
          else plano[j][i] = fill;

        }
    }
}

void fill_plane(int **plano, int x_max, int y_max){
    for(int i = 0; i<y_max; i++){
        for(int j = 0; j<x_max; j++){ //llena el plano con 0's
          plano[i][j] = 0;
        }
    }
}

void calculate_intersection(int **plano, int x_max, int y_max, int *res, short fill){

    bool corner = false, wide = false;
    int current = 0, ancho = 0, i = 0, j = 0, area = 1;

    fill += 2;

    for(i = 0; i<y_max; i++){ //recorre filas

        for(j = 0; j<x_max; j++){ //recorre columnas

            current = plano[i][j]; //numero actual

            if(current == fill && corner == false) {//solo calcula la esquina una vez
                res[0] = j; // x de la esquina
                res[1] = i; // y de la esquina
                corner = true;
                wide = true; //activa el contador del ancho
            }
            else if(current == fill && corner == true) area++; //va sumando al area del rectangulo

            if(current == fill && wide == true) ancho++; //va sumando al ancho del rectangulo
        }

        if(wide == true) wide = false; //deja de contar despues de que cuenta las columnas una vez
    }

    if(ancho>0){
        res[2] = ancho;
        res[3] = area/ancho;
    }
    else for(int k = 0; k<4; k++) res[k] = 0;
}

//Problema 16
unsigned long long travel_grid(int k){

 /*
Se observa que sin importar el camino que se tome el numero de movimientos hacia la derecha es igual al numero de movimientos hacia abajo (2n).
por tanto, el problema se reduce a encontrar el numero de combinaciones de dichos movimientos 2nCn (se usa combinacion y no permutacion ya que
muchos caminos se repiten, y la combinacion se encarga de no tener estos en cuenta)
*/

    return comb(2*k, k);

}

unsigned long long comb(int n, int r){
/*
Por formula se desbordan los valores ya que son numeros absurdamente grandes

    unsigned long long res;
    unsigned long long fact_n = fact(n), fact_k = fact(k), fact_n_k = fact(n-k);

    res = (fact_n)/(fact_k*fact_n_k);

    return res;

En cada iteración se dividen las variables actuales que tienen el valor de los productos por su mcd.
Asi se evita el desbordamiento (para valores grandes se desborda de igual modo (n>~30))
Esto tambien evita el calculo de factoriales.
*/

    unsigned long long p = 1, k = 1;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            unsigned long long m = __gcd(p, k); // maximo comun divisor de p y k

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    return p;
}

//Problema 17
int get_divisores_sum(int n){

    int res = 0;

    for (int i=1, temp; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            temp = n/i;

            if (temp == i) res += i;

            else res += i + temp;
        }
    }
    return res - n;
}

long sum_friendly_smaller_than_n(int n){

    long sum = 0;

    cout<<"Procesando..."<<endl;

    for (int num1 = 220;  num1 < n;  ++num1) {
        int num2 = get_divisores_sum(num1);
        if (num2 > num1 && num1 == get_divisores_sum(num2))  {
           //cout<<num1<<' '<<num2<<endl;
           sum+= num1+num2;
        }
    }
    return sum;
}

//Problema 18
void n_permutation(int n){

      int digits[] = {0,1,2,3,4,5,6,7,8,9};

      for(int count = 1; count<n; count++){

          next_permutation(digits,digits+10);

      }

      cout<<"La permutacion numero "<<n<<" es: ";

      for(int i = 0; i < 10; i++)
          cout << digits[i];
      cout<<endl;

}











