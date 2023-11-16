#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char * dec_to_bin(int num);
void bin_write(char * input);
int bin_to_dec(char * input_bin);
void bin_read();

int invertBits(int num) {
  num = num ^ 0b00001111;
  return num;
}



int main(){
//  bin_write("bibanutie");
  bin_read();
  return 0;
}

void bin_read(){
  FILE * file = fopen("zero_and_one.txt", "r");
  char buffer[9];  // Массив для хранения 8 символов + 1 символ конца строки ('\0')
  int c;
  size_t index = 0;

  while ((c = fgetc(file)) != EOF) {
    if (index % 8 == 0) {
      buffer[index] = '\0';  // Добавляем нулевой символ в конец массива
      int tmp = invertBits(bin_to_dec(buffer));
      printf("%c", tmp);
      index = 0;
    }
    buffer[index] = c;
    index++;
  }

  if (index > 0){
    buffer[index] = '\0';
    int tmp = invertBits(bin_to_dec(buffer));
    printf("%c", tmp);
  }

  fclose(file);  // Закрываем файл

}

void bin_write(char * input){
  FILE * stream = fopen("zero_and_one.txt", "w");

  for (int i =0; i< strlen(input); i++) {
    int tmp = invertBits(input[i]); //инвертнули

    char * binary = dec_to_bin(tmp); //из 10 в 2

    fprintf(stream,"%s", binary); // положили

    free(binary); //освободили то что заняли в dec_to_bin
  }

}

char * dec_to_bin(int num){
  char * result = (char *)malloc(9);

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

  for (int i = 0; i < 8; i++) {
    if(input_bin[7 - i] == '1') result += pow(2, i);
  }

  return result;
}

