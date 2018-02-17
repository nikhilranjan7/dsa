#include <stdio.h>
#include <stdlib.h>
#include "que.h"
#include "multiq.h"

MultiQ loadData(FILE* f){
  int t, p;
  MultiQ mq = createMQ(11);
	f = fopen("input10.txt", "r");

	while (!feof(f))
	{
		fscanf(f, "%d,%d", &t,&p);
    Element e = newElement(t, p);
    mq = addMQ(mq, e);
	}
	fclose(f);
  return mq;
}

MultiQ testDel(MultiQ mq, int num){
  int i = 0;
  for(i=0;i<num;i++){
    mq = delNextMQ(mq);
  }
  return mq;
}
