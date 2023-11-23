#include "../hello.h"

int main(){
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  char input[] = "DEVa";

  char * first_step = (char *)malloc(strlen(input) * 8); // для 1 и 0
  char * second_step = (char *)malloc(6 + 1); // для base64 переменной
  char * padding = (char *)malloc(2 + 1);

  int len_base_64 = add_to_3(strlen(input)) / 3 * 4;
  int diff = (len_base_64 - strlen(input));

  if(strlen(input) == 2)
    strcpy(padding, "==");
  else if (strlen(input)== 1)
    strcpy(padding, "=");

  FILE *fp = fopen("asd.txt", "w");


  for (int i = 0; i < strlen(input); ++i) {
    char * tmp = dec_to_bin(input[i]);
    strcat(first_step,tmp);
    free(tmp);
  }



  for (int i = 0; i < strlen(first_step); ++i) {
    second_step[i % 6] = first_step[i];
    if ((i + 1) % 6 == 0 && i != 0){
      int index_in_alphabet = bin_to_dec(second_step);

      char tmp = alphabet[index_in_alphabet];
      fwrite(&tmp, sizeof(char), 1, fp);
    }
  }

  fprintf(fp, "%s", padding);
  free(first_step);
  return 0;
}

