#ifndef UNTITLED1_HELLO_H
#define UNTITLED1_HELLO_H
#define BUFF_SIZE 100

#include <stdio.h>
#include <stdlib.h>

struct input_data{
    char url_address[BUFF_SIZE];
    int ip_arr[4];
};

union bibki{
    struct input_data sas;
    char buffer[sizeof(struct input_data)];
};

int get_data(union bibki * input);
void print_data(union bibki * output);
void write_in_file();
void bite_print(union bibki output);


#endif //UNTITLED1_HELLO_H
