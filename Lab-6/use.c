#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "implement.h"

emp copyEmp(emp e){
    emp a = (emp)malloc(sizeof(struct employee));
    a->name = (char*)malloc(10*sizeof(char));
    int i;
    for(i = 0; e->name[i] != '\0'; ++i)
    {
        a->name[i] = e->name[i];
    }
    a->empID = e->empID;

    return a;
}

// Insertion Sort
void insertionSort(emp_arr arr, int n){
   int i, j;
   emp key = (emp)malloc(sizeof(struct employee));
   for (i = 1; i < n; i++)
   {
       key = copyEmp(arr[i]);
       j = i-1;

       while (j >= 0 && arr[j]->empID > key->empID)
       {
           arr[j+1] = copyEmp(arr[j]);
           j = j-1;
       }
       arr[j+1] = copyEmp(key);
   }
}

// Quick Sort
void swap(emp* a, emp* b){
    emp i = copyEmp(*a);
    *a = copyEmp(*b);
    *b = copyEmp(i);
}

int partition (emp_arr arr, int low, int high){
    emp pivot = copyEmp(arr[high]);    // pivot
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j]->empID <= pivot->empID)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(emp_arr arr, int low, int high){
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void optimized_quickSort(emp_arr arr, int low, int high){
    if (low < high)
    {

        int pi = partition(arr, low, high);
        if(pi-1 - low > 20){
        quickSort(arr, low, pi - 1);
        }
        else{
        insertionSort(&arr[low], pi-low);
        }

        if(high-pi-1 > 20){
        quickSort(arr, pi + 1, high);
        }
        else{
        insertionSort(&arr[pi+1], high-pi);
        }
    }
}

int testRun(emp_arr e_ar, int n, double tim[]){
  struct timeval t1, t2;
  double elapsedTime;

  //start time
  gettimeofday(&t1, NULL);
  quickSort(e_ar, 0, n-1);
  gettimeofday(&t2, NULL);

  elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  tim[0] = elapsedTime;

  e_ar = loadData();

  gettimeofday(&t1, NULL);
  insertionSort(e_ar, n);
  gettimeofday(&t2, NULL);

  elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  tim[1] = elapsedTime;

  if (tim[0] >= tim[1]){
    return 1;
  }
  return 0;
}

int estimateCutoff(){
    double tim[2] = {0.0, 0.0};
    int i = 0;
    emp_arr e_ar = loadData();
    int tt1 = testRun(e_ar, 0, tim);

    e_ar = loadData();
    int tt2 = testRun(e_ar, 2000, tim);
    while(tt1 != tt2){
      emp_arr e_ar = loadData();
      int tt1 = testRun(e_ar, i, tim);

      e_ar = loadData();
      int tt2 = testRun(e_ar, 2000-i, tim);
      i++;
    }
    return i;
}

int main(){
    emp_arr e_ar = loadData();
/*
    int j = 0;
	for(j=0;j<10;j++){
	    printf("%s--%lli\n",e_ar[j]->name,e_ar[j]->empID);
	}

	printf("\nSORTIING\n");
	quickSort(e_ar, 0, 1999);

	for(j=0;j<10;j++){
	    printf("%s--%lli\n",e_ar[j]->name,e_ar[j]->empID);
	}
  */
    double tim[2] = {0.0, 0.0};
    testRun(e_ar, 2000, tim);
    printf("QuickSort time: %lf ms\nInsertionSort time: %lf ms\n",tim[0],tim[1]);
    int a = estimateCutoff();
    printf("Cutoff point is: %d",a);
    return 0;
}
