#include<stdio.h>
#include<stdlib.h>
#define Elemtype char
#define status int
#define OVERFLOW -2
#define OK 1

typedef struct qNode {
	Elemtype data;
	struct qNode* next;
}QNode,*QNodePtr;

typedef struct {
	QNodePtr front;
	QNodePtr rear;
}LinkQueue;

status InitQueue(LinkQueue *Q) {
	Q->front = (QNode*)malloc(sizeof(QNode));
	if (!Q->front)
		exit(-1);
	Q->rear = Q->front;
	Q->front->next = NULL;
	return OK;
}

status DestoryQueue(LinkQueue* Q) {
	while (Q->front) {
		QNodePtr p = Q->front->next;
		free(Q->front);
		Q->front = p;
	}
	return OK;
}

status EnQueue(LinkQueue* Q,Elemtype e) {
	QNodePtr s = (QNodePtr)malloc(sizeof(QNode));
	if (!s)
		return OVERFLOW;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}

Elemtype DeQueue(LinkQueue *Q) {
	if (Q->front == Q->rear)
		exit(OVERFLOW);
	QNodePtr p = Q->front->next;
	Q->front->next = p->next;
	Elemtype e = p->data;
	if (p == Q->rear)
		Q->rear = Q->front;
	free(p);
	return e;
}

void Print(LinkQueue Q) {
	QNodePtr p = Q.front->next;
	while (p) {
		printf("%c\t", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	LinkQueue Q;
	InitQueue(&Q);
	for (int i = 0; i < 5; i++) {
		char c = getchar();
		EnQueue(&Q, c);
		Print(Q);
	}
	DeQueue(&Q);
	Print(Q);
	DestoryQueue(&Q);
	return OK;
}
