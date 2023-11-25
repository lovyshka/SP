#include "../hello.h"

int main(int argc, char *argv[]){
  union bibi read_out = {0};

  if (argc > 2) {
    printf("error #4- to much arguments ");
    return 2;
  }

  char * filename = argv[1];
  FILE *fp = fopen(filename, "r");
  if (fp == NULL){
    printf("error #3 - failed to open\n");
  }
  else {
    bites_read(&read_out, fp);
    print_data(&read_out);
  }
  return 0;
}