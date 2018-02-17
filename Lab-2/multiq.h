typedef Element Task;

struct multiQ{
  Queue q;
  int size;
};
typedef struct multiQ* MultiQ;

MultiQ createMQ(int num);

MultiQ addMQ(MultiQ mq, Task t);

Task nextMQ(MultiQ mq);

MultiQ delNextMQ(MultiQ mq);

int isEmptyMQ(MultiQ mq);

int sizeMQ(MultiQ mq);

int sizeMQbyPriority(MultiQ mq, int p);

Queue getQueueFromMQ(MultiQ, int p);

void printq(MultiQ mq);
