#include <stdio.h>
#include <stdlib.h>
unsigned long int space = 0;

void* myalloc(unsigned long int m){
  space += m;
  void* a = (void*)malloc(m);
  return a;
}

void myfree(void* m){
  space -= sizeof(m);
  free(m);
}


int main(){
  unsigned long int s= 10000;
  printf("%lu\n",space);
  int* m = myalloc(s);
  printf("%p\n%p\n",&m[0],&m[s-1]);
  printf("%lu\n",space);
  myfree(m);
  printf("%lu\n",space);
  printf("%p\n%p\n",&m[0],&m[s-1]);
}
