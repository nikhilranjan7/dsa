typedef Element Task;

struct multiQ{
  Queue *q;
  int size;
};
typedef multiQ MultiQ;

MultiQ createMQ(int num);

MultiQ addMQ(MultiQ mq, Task t);

Task nextMQ(MultiQ mq);

MultiQ delNextMQ(MultiQ mq);

Task isEmptyQ(MultiQ mq);

int sizeMQ(MultiQ mq);

int sizeMQbyPriority(MultiQ mq, int p);

Queue getQueueFromMQ(MultiQ, int p);
