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
    unsigned char buffer[sizeof(struct input_data)];
};

int get_data(union bibi * input); //считывание с консоли
void print_data(union bibi * output); // просто печать того что мы ввели
int invertBits(int num); //шифрование
void write(union bibi write_in); // запись в файл
void read(union bibi * read_out); // чтение из файла
int check_ip(struct input_data d); //проверка на инициализированность айпишников

#endif //UNTITLED1_HELLO_H
