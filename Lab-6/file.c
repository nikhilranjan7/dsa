#include <stdio.h>
#include <stdlib.h>
#include "implement.h"

emp_arr loadData(){
  FILE* f;
  char* c;
  c = (char*)malloc(10*sizeof(char));
  long long int n;
  emp_arr e_ar = init(2001);
  f = fopen("data.txt", "r");
  int i = 0;
	while (!feof(f))
	{
		fscanf(f, "%s %lli", c,&n);
		//printf("%s\n",c);
        e_ar[i] = newEmp(c, n);
        i += 1;
	}
	fclose(f);

  return e_ar;
}


