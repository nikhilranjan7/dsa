//Driver file
#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

int main(){
  SeqList s1 = newList();
  s1 = insertAtFront(s1, newElement(1));
  s1 = insertAtFront(s1, newElement(2));
  s1 = insertAtFront(s1, newElement(3));
  Element a = newElement(5);
  s1 = insertAtEnd(s1, a);
  s1 = insertAtEnd(s1, newElement(2));
  s1 = insertAtEnd(s1, newElement(3));
  print(s1->front);
  s1 = del(s1, a);
  printf("\n");
  print(s1->front);
  printf("\n");
}
/*
gcc -c SeqList.c -o SeqList.o
gcc -c driver.c -o driver.o
gcc SeqList.o driver.o -o prog
./prog
*/
