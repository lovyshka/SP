#ifndef UNTITLED1_HELLO_H
#define UNTITLED1_HELLO_H
#define BUFF_SIZE 100
#define ERROR_1 printf("error #2 - invalid input data, check the format\n")


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct input_data{
    char url_address[BUFF_SIZE];
    int ip_arr[4];
};

union bibi {
    struct input_data sas;
    char buffer[sizeof(struct input_data)];
};

int get_data(union bibi * input); //считывание с консоли
void print_data(union bibi * output); // просто печать того что мы ввели
int invertBits(int num); //шифрование
void bites_write(union bibi write_in); // запись в файл
void bites_read(union bibi * read_out); // чтение из файла
int check_ip(struct input_data d); //проверка на инициализированность айпишников
char * dec_to_bin(int num); //10 в 2
int bin_to_dec(char * input_bin); // 2 в 10
void bin_read(union bibi *opt); //чтение
void bin_write(union bibi opt); //запись
int add_to_3(int num); // добавить до 3-х

#endif //UNTITLED1_HELLO_H
