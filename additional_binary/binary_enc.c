#include "../hello.h"


int main(){
  union bibi write_in = {0};
  if (get_data(&write_in) == 1){
    bin_write(write_in.buffer);
  }
  else ERROR_1;
  return 0;
}

