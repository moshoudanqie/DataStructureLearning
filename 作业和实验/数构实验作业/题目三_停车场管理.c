#include<stdio.h>
#include<stdlib.h>
#define PARKSIZE 2
#define status int
#define OK 1
#define OVERFLOW -2
typedef struct Car {
	char state;//��ȥ���ߵ���
	int LPN;//���ƺ�
	int moment;//ʱ��
}Car;
typedef struct {
	Car *base,*top;
	int stacksize;
}Stack;//ͣ����


typedef struct QNode {
	Car car;
	struct QNode* next;
}QNode,*QNodePtr;
typedef struct {
	QNodePtr front;
	QNodePtr rear;
	int length;
}LinkQueue;//���

//��ʼ��ͣ���������
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
//��ʼ�����
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
//����ջ�Ͷ���
void show() {
	Stack park, space;
	LinkQueue sideway;
	InitStack(&park, PARKSIZE);
	InitStack(&space, PARKSIZE - 1);
	InitQueue(&sideway);
	//��ʼ��ͣ����������
	
	char state;
	Car e;
	while (1) {
		printf("here\n");
		scanf("%c %d %d", &state, &e.LPN, &e.moment);
		if (state == 'A') {
			if (park.top - park.base == PARKSIZE) {
				EnQueue(&sideway, e);
				printf("�������ڱ���ϵ�%d��λ��\n", sideway.length);
			}
			//����ڱ����λ�ã����Ӧ�������len
			else {
				PushS(&park, e);
				printf("��������ͣ�����ĵ�%d��λ��\n", park.top - park.base);
				//�����ͣ������λ�ã�
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
			printf("�˳���ͣ������ͣ��ʱ��Ϊ%d min\nӦ�ý���ͣ�����ã�%d", e.moment - c1.moment,e.moment - c1.moment);
			//���ͣ��ʱ��ͽ��ɷ���
			while (space.top != space.base) {
				PopS(&space, &c1);
				PushS(&park, c1);
			}
			if(sideway.length){
			
			DeQueue(&sideway, &c1);
			c1.moment = e.moment;
			PushS(&park, c1);}
			//����ȥ�ĳ���ʱ�̸�ֵ��car
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
	//����
}

