#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

Queue newQueue() {
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;	
	return q;
}

void destroyQueue(Queue *q) {
	clear(*q);
	free(*q);
	*q=NULL;
}

void enqueue(Queue q,qItem item) {
	nodeptr p = (nodeptr)malloc(sizeof(struct node));
	p->item = item;
	p->next = NULL;
	if (q->rear == NULL) {
		q->front = p;
	} else {
		q->rear->next = p;
	}
	q->rear = p;	
}
void dequeue(Queue q) {
	nodeptr p;
	if (q->front != NULL) {
		p = q->front;
		q->front = p->next;
		free(p);
		if (q->front == NULL)		
			q->rear = NULL;		
	}
	
}

// not empty
qItem peek(Queue q) {
	return q->front->item;
}

void display(Queue q) {
	nodeptr p = q->front;
	printf("[");
	while (p!=NULL){
		printf("\t%d",p->item);
		p = p->next;
	}
	printf("]");
}

void clear(Queue q) {
	while(q->front!=NULL){
		nodeptr p=q->front;
		//if(p!=NULL){
		q->front = p->next;
		free(p);
		//}
	}
	q->rear=NULL;
}

boolean isEmpty(Queue q) {
	return (q->front != NULL ? false :true);
}


