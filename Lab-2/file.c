#include <stdio.h>
#include <stdlib.h>
#include "que.h"
#include "multiq.h"

MultiQ loadData(File* f){
  int t, p;
  MultiQ mq = createMQ(10);
	f = fopen("input10.txt", "r");
  /*
	Element *data;
	data = (Element*)malloc(2000*sizeof(Element));
	int j = 0;
  */
	while (!feof(f))
	{
		fscanf(f, "%d,%d", &t,&p);
    Element e = newElement(t, p);
    mq = addMQ(mq, e);
	}
	fclose(fp);

  return mq;
}

MultiQ testDel(MultiQ mq, int num){
  int i = 0;
  for(i=0;i<num;i++){
    mq = delNextMQ(mq);
  }
}

int main(){
	FILE *fp;
	int t, p;
	fp = fopen("input10.txt", "r");
  /*
	Element *data;
	data = (Element*)malloc(2000*sizeof(Element));
	int j = 0;
  */
	while (!feof(fp))
	{
		fscanf(fp, "%d,%d", &t,&p);
    printf("%d, %d\n", t,p);
	}
	fclose(fp);
}
