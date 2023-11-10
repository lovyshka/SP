#ifndef UNTITLED1_HELLO_H
#define UNTITLED1_HELLO_H
#define BUFF_SIZE 100


#include <stdio.h>
#include <stdlib.h>

struct input_data{
    char url_address[BUFF_SIZE];
    char ip_address[BUFF_SIZE];
};

union bibki{
    struct input_data sas;
    char * arr[sizeof(struct input_data)];
};

void get_data(struct input_data * input);

#endif //UNTITLED1_HELLO_H
