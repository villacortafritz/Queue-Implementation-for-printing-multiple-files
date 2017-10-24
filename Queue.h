#ifndef QUEUE_H
#define QUEUE_H
#define n 5

typedef enum {false, true} boolean;
typedef struct node *nodeptr;
typedef int qItem;
struct node {
	qItem item;
	nodeptr next;	
};

struct queue {
	nodeptr front;
	nodeptr rear;
};

typedef struct queue *Queue;

Queue newQueue();
void destroyQueue(Queue *q);
void enqueue(Queue q,qItem item);
void dequeue(Queue q);
qItem peek(Queue q);
void display(Queue q);
void clear(Queue q);
boolean isEmpty(Queue q);





#endif
