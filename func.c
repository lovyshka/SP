#include "hello.h"


void bites_read(union bibi * read_out, FILE * fp) {

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

void bin_read(union bibi *opt, FILE * fp){

    int c;
    size_t index = 0;
    for (int i = 0; i < sizeof (union bibi); i++){
        char buffer[8];
        fread(buffer, sizeof(buffer), 1, fp);

        int num = bin_to_dec(buffer);

        opt->buffer[i] = invertBits(num);
    }

    fclose(fp);  // Закрываем файл

}


void bites_write(union bibi write_in, FILE *fp){
    char * tmp = (char *)malloc(sizeof (char));

    for (int i = 0; i < sizeof (union bibi); i++){

        tmp = (char *)realloc(tmp, sizeof (char) * (i + 1));
        tmp[i] = invertBits(write_in.buffer[i]);

    }

    for (int i = 0; i < sizeof(union bibi); ++i) {

        char c = tmp[i];
        fwrite(&c, sizeof(char), 1, fp);

    }

    free(tmp);
}

void bin_write(union bibi opt, FILE * fp){

    char * tmp = (char *)malloc(sizeof (char));
    strcpy(tmp, opt.buffer);

    for (int i =0; i< sizeof(union bibi); i++) {

        tmp = (char *)realloc(tmp, sizeof(char) * (i + 1));
        tmp[i] = invertBits(opt.buffer[i]); // инвертнули
    }

    for (int i = 0; i < sizeof (union  bibi); ++i) {

        char * binary = dec_to_bin(tmp[i]); //из 10 в 2

        fprintf(fp,"%s", binary); // положили

        free(binary); //освободили то что заняли в dec_to_bin

    }
    free(tmp);
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
        if(input_bin[(len - 1) - i] == '1') result += (int)powf(2, i);
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




