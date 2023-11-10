#include "hello.h"


int main() {
    struct input_data input = {0};
    get_data(&input);

    return 0;
}

void get_data(struct input_data * input){
    printf("Input your data in format \"[url of the site] [ip address]\"\n");
    scanf("%s %s", input -> url_address, input -> ip_address);
}