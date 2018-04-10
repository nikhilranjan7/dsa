#include <stdio.h>
#include <stdlib.h>
#include "implement.h"


emp newEmp(char* n, long long int y){
    emp e = (emp)malloc(sizeof(struct employee));
    e->name = (char*)malloc(10*sizeof(char));
    int i;
    for(i = 0; n[i] != '\0'; ++i)
    {
        e->name[i] = n[i];
    }
    e->empID = y;

    return e;
}

emp_arr init(long long int n){
    emp_arr e_arr = (emp_arr)malloc(n*sizeof(emp));
    return e_arr;
}
