#include "../hello.h"


int main(){
  union bibi read_out = {0};
  bin_read(&read_out);
  print_data(&read_out);
  return 0;
}