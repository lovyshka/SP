#include "hello.h"

void bites_write(union bibi write_in){
    FILE * fp = fopen("binary", "wb");

    for (int i = 0; i < sizeof (union bibi); i++){

      int tmp = invertBits(write_in.buffer[i]);

      fwrite(&tmp, sizeof(tmp), 1, fp);

    }
}

void bites_read(union bibi * read_out) {
    FILE *fp = fopen("binary", "r");

    for (int i = 0; i < sizeof(union bibi); i++) {

      int tmp;
      fread(&tmp, sizeof(tmp), 1, fp);
      tmp = invertBits(tmp);

      read_out -> buffer[i] = tmp;
    }
}


int get_data(union bibi * b){
    int flag = 0;
    int read;
    char temp;
    printf("Input your data in format \"[url of the site] [ip address]\"\n");
    printf("Be worry that maximum length of url is 100 char\n");
    if ((read = scanf("%s%c%d.%d.%d.%d", (b -> sas.url_address), &temp, &(b -> sas.ip_arr[0]), &(b -> sas.ip_arr[1]), &(b -> sas.ip_arr[2]), &(b -> sas.ip_arr[3]))) == 6 && (temp == ' ') && (check_ip(b -> sas) != 1) && (b->sas.url_address != 0)) flag = 1;

    return flag;
}

void print_data(union bibi * b){
    printf("%s ", b -> sas.url_address);
    for (int i = 0; i < 4; i++) {
        if (i == 3) printf("%d\n", b -> sas.ip_arr[i]);
        else printf("%d.",  b -> sas.ip_arr[i]);
    }
}

int invertBits(int num) {
    num = num ^ 15;
    return num;
}

int check_ip(struct input_data d){
    int ans = 0;
    if (d.ip_arr[0] == 0 && d.ip_arr[1] == 0 && d.ip_arr[2] == 0 && d.ip_arr[3] == 0) ans = 1;
    return ans;
}

