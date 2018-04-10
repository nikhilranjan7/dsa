#include <stdio.h>

int bits;

int p(pi){
  int pilani=pi;
  printf("Inside Pilani: %p\n",&pilani);
  return p(pi+1);
}

void g(){
  int goa=1;
  printf("Inside Goa: %p\n",&goa);
}

void h(){
  int hyd=2;
  printf("Inside hyd: %p\n",&hyd);
}

void d(){
  int dub=3;
  printf("Inside Dubai: %p\n",&dub);
}

int main(){
  printf("Inside Main\n");
  p(0);
  printf("Global variable: %p\n",&bits);
}
