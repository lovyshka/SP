#include "hello.h"

int main() {
    union bibki b = {0};
    get_data(&b);

    return 0;
}

void bite_print(union bibki output){
    for (int i = 0; i < sizeof(union bibki); ++i){
      if (i == 0) printf("%c ",output.buffer[i]);
      else
        printf("%d", output.buffer[i]);
    }
    printf("\n");
}

void write_in_file(union bibki output){
    FILE * stream = fopen("binary", "w+");
    for (int i = 0; i < sizeof(output); i++){
      fwrite(output.buffer[i], sizeof(output.buffer[i]), 1, stream);
    }
}

void read_from_file(union bibki input){
    FILE * stream = fopen("binary", "r");
    for (int i = 0; i < sizeof (input); i++){
      fread(input.buffer[i], sizeof(output.buffer[i], 1, stream));
    }
}

int get_data(union bibki * b){
    int flag = 0;
    printf("Input your data in format \"[url of the site] [ip address]\"\n");
    printf("Be worry that maximum len of url is 100 char\n");
    if ((scanf("%s %d.%d.%d.%d", (b -> sas.url_address), &(b -> sas.ip_arr[0]), &(b -> sas.ip_arr[1]), &(b -> sas.ip_arr[2]), &(b -> sas.ip_arr[3]))) == 5) flag = 1;
    return flag;
}

void print_data(union bibki * b){
    printf("%s\n", b -> sas.url_address);
    for (int i = 0; i < 4; i++) {
        if (i == 3) printf("%d\n", b -> sas.ip_arr[i]);
        else printf("%d.",  b -> sas.ip_arr[i]);
    }
}