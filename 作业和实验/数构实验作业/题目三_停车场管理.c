#include<stdio.h>
#include<stdlib.h>
#define PARKSIZE 2
#define status int
#define OK 1
#define OVERFLOW -2
typedef struct Car {
	char state;//离去或者到达
	int LPN;//车牌号
	int moment;//时刻
}Car;
typedef struct {
	Car *base,*top;
	int stacksize;
}Stack;//停车场


typedef struct QNode {
	Car car;
	struct QNode* next;
}QNode,*QNodePtr;
typedef struct {
	QNodePtr front;
	QNodePtr rear;
	int length;
}LinkQueue;//便道

//初始化停车场，便道
status InitStack(Stack* P,int n) {
	P->base = (Car*)malloc(n*sizeof(Car));
	if (!P->base)
		exit(-2);
	P->top = P->base;
	P->stacksize = PARKSIZE;
	return OK;
}

status InitQueue(LinkQueue *Q) {
	Q->front = (QNodePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(-2);
	Q->rear = Q->front;
	Q->length = 0;
}
//初始化便道
status PushS(Stack* S, Car e) {
	if (S->top - S->base == S->stacksize)
		return OVERFLOW;
	*S->top = e;
	S->top++;
	return OK;
}
//push
status PopS(Stack* S, Car* e) {
	if (S->top == S->base)
		exit(-2);
	*e = *(--S->top);
	return OK;
}
//pop
status EnQueue(LinkQueue *Q,Car e) {
	if (!Q->front)
		exit(-2);
	QNodePtr s = (QNode*)malloc(sizeof(QNode));
	if (!s)
		exit(-2);
	s->car = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	Q->length++;
	return OK;
}
//Enqueue
status DeQueue(LinkQueue* Q, Car* e) {
	if (Q->front == Q->rear)
		return OVERFLOW;
	QNodePtr p = Q->front->next;
	if (p == Q->rear)
		Q->rear == Q->front;
	*e = p->car;
	Q->front->next = p->next;
	free(p);
	Q->length--;
	return OK;
}
//Dequeue

void PrintStack(Stack S){
	Car* p = S.base;
	while(p<S.top){
		printf("%d\t",p->LPN);
		p++;
	}
}
void PrintQueue(LinkQueue Q){
	QNode* p =Q.front->next;
	for(int i = 0;i<Q.length;i++){
		printf("%d\t",p->car.LPN);
		p = p->next;
	}
}
void DestroyStack(Stack* S) {
	free(S->base);
	S->base = NULL;
	S->top = S->base;
	S->stacksize = 0;
}

void DestoryQueue(LinkQueue* Q) {
	Q->rear = Q->front;
	while (Q->rear) {
		Q->front = Q->rear->next;
		free(Q->rear);
		Q->rear = Q->front;
	}
	Q->length = 0;
}
//销毁栈和队列
void show() {
	Stack park, space;
	LinkQueue sideway;
	InitStack(&park, PARKSIZE);
	InitStack(&space, PARKSIZE - 1);
	InitQueue(&sideway);
	//初始化停车场，车道
	
	char state;
	Car e;
	while (1) {
		printf("here\n");
		scanf("%c %d %d", &state, &e.LPN, &e.moment);
		if (state == 'A') {
			if (park.top - park.base == PARKSIZE) {
				EnQueue(&sideway, e);
				printf("这辆车在便道上第%d车位上\n", sideway.length);
			}
			//输出在便道的位置，便道应该设参数len
			else {
				PushS(&park, e);
				printf("这辆车在停车场的第%d车位上\n", park.top - park.base);
				//输出在停车场的位置；
			}
		}
		else if (state == 'D') {
			Car c1;
			while ((park.top - 1)->LPN != e.LPN) {
				PopS(&park, &c1);
				PushS(&space, c1);
			}
			//delete car;
			PopS(&park, &c1);
			printf("此车在停车场中停留时间为%d min\n应该缴纳停车费用：%d", e.moment - c1.moment,e.moment - c1.moment);
			//输出停留时间和缴纳费用
			while (space.top != space.base) {
				PopS(&space, &c1);
				PushS(&park, c1);
			}
			if(sideway.length){
			
			DeQueue(&sideway, &c1);
			c1.moment = e.moment;
			PushS(&park, c1);}
			//把离去的车的时刻赋值给car
		}
		else if (state == 'E') {
			DestoryQueue(&sideway);
			DestroyStack(&park);
			DestroyStack(&space);
			exit(-2);
		}
		PrintStack(park);
		PrintQueue(sideway);
		printf("\n");
	}
	DestoryQueue(&sideway);
	DestroyStack(&park);
	DestroyStack(&space);
}

int main() {
	show();
	return 0;
	//销毁
}

