#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i, pages=0, exec=0, wait=0, turn=0, waitStore=0, turnStore=0, count=0;
	Queue q = newQueue();
	
	printf("Processing Time:\t5 seconds");
	enqueue(q,40);
	enqueue(q,20);
	enqueue(q,30);
	enqueue(q,5);
	enqueue(q,2);
	printf("\nPage No.");
	display(q);
	printf("\n\nPages\t\tExecution\tWaiting\t\tTurn Around\n");
	
	while(!isEmpty(q)){
		pages = peek(q);
		exec = pages*n;
		wait = turn;
		waitStore+=wait;
		turn = exec + wait;
		turnStore+=turn;
		
		printf("\n%d", pages);
		printf("\t\t%d", exec);
		printf("\t\t%d", wait);
		printf("\t\t%d", turn);
		
		dequeue(q);
		count++;
	}
	
	printf("\n\nAverage Waiting Time:\t\t%d", waitStore/count);
	printf("\nAverage Turn Around Time:\t%d", turnStore/count);
	
	destroyQueue(&q);
	

	return 0;
}

