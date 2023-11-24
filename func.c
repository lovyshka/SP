#include "hello.h"


void bites_read(union bibi * read_out) {
    FILE *fp = fopen("binary.txt", "r");

    for (int i = 0; i < sizeof(union bibi); i++) {

      char tmp;

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

void bin_read(union bibi *opt){
    FILE * file = fopen("zero_and_one.txt", "r");

    int c;
    size_t index = 0;
    for (int i = 0; i < sizeof (union bibi); i++){
        char buffer[8];
        fread(buffer, sizeof(buffer), 1, file);

        int num = bin_to_dec(buffer);

        opt->buffer[i] = invertBits(num);
    }

    fclose(file);  // Закрываем файл

}


void bites_write(union bibi write_in){
    FILE * fp = fopen("binary.txt", "wb");

    for (int i = 0; i < sizeof (union bibi); i++){

        char tmp = invertBits(write_in.buffer[i]);

        fwrite(&tmp, sizeof(tmp), 1, fp);

    }
}
void bin_write(union bibi opt){
    FILE * stream = fopen("zero_and_one.txt", "w");

    for (int i =0; i< sizeof(union bibi); i++) {

        int tmp = invertBits(opt.buffer[i]); //инвертнули

        char * binary = dec_to_bin(tmp); //из 10 в 2

        fprintf(stream,"%s", binary); // положили

        free(binary); //освободили то что заняли в dec_to_bin
    }
}

char * dec_to_bin(int num){
    char * result = (char *)calloc(9, 1);
    result[8] = '\0';

    for (int i = 0; i < 8; ++i) {

        if (num % 2 == 1) result[7 - i] = '1';
        else result[7 - i] = '0';
        num = num / 2;

    }
    return result;
}

int bin_to_dec(char * input_bin){
    int result = 0;
    int len = strlen(input_bin);
    for (int i = 0; i < len; i++) {
        if(input_bin[(len - 1) - i] == '1') result += pow(2, i);
    }

    return result;
}

int add_to_3(int num){
    if (num % 3 != 0){
        num += 1;
        add_to_3(num);
    }
    else
      return num;
}



void kal(){
    int buff[20];
    for (int i = 0; i < 20; ++i) {
      scanf("%d", buff[i]);
    }

    for (int i = 0; i < sizeof (buff)/sizeof (int); ++i) {

    }
}
