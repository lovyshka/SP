#include "../hello.h"

int main(int argc, char * argv[]){
  union bibi write_in = {0};

  if (argc > 2) {
    printf("error #4- to much arguments ");
    return 2;
  }

  char *filename = argv[1];
  FILE *tmp  = fopen(filename, "wb");
  if ((tmp) == NULL){
    printf("error #3 - failed to open file");
    return 1;
  }
  else if (get_data(&write_in) == 1){
    bites_write(write_in, tmp);
  }
  else ERROR_1;

  return 0;
}