#include<stdio.h>
#include<stdlib.h>
#define status int 
#define MAXSIZE 5
#define Elemtype char
#define OVERFLOW -2
#define OK 1;
#define ERROR 0;
typedef struct {
	Elemtype* base;
	int front;
	int rear;
}Queue;

status InitQueue(Queue *Q) {
	Q->base = (Elemtype*)malloc(MAXSIZE * sizeof(char));
	if (!Q->base)
		return OVERFLOW;
	Q->front = 0;
	Q->rear = Q->front;
}

int QueueLength(Queue Q) {
	if (!Q.base)
		return;
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

status EnQueue(Queue* Q,Elemtype e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return OVERFLOW;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Elemtype DeQueue(Queue* Q) {
	if (Q->front == Q->rear)
		return ERROR;
	Elemtype p = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return p;
}

Elemtype GetHead(Queue Q) {
	if (!Q.base)
		return OVERFLOW;
	return Q.base[Q.front];
}

void Print(Queue Q) {
	if (!Q.base)
		return;
	int p = Q.front;
	while (p != Q.rear) {
		printf("%c\t", Q.base[p]);
		p = (p + 1) % MAXSIZE;
	}
	printf("\n");
}

void DestoryQueue(Queue* Q) {
	free(Q->base);
	Q->base = NULL;
}


int main() {
	Queue Q;
	InitQueue(&Q);
	for (int i = 0; i < 5; i++) {
		char c = getchar();
		EnQueue(&Q, c); Print(Q);
	}
	char a = DeQueue(&Q);
	printf("%c\n",a);
	printf("%c\n", GetHead(Q));
	Print(Q);
	DestoryQueue(&Q);
}


