/*
1.Ϊ�˲������㣬ͨ��topָʾ������ջ��Ԫ��֮�ϵ��±�λ��
2.��ջ��־��top-base=0
3.ջ����־��top-base = size
*/


#include<stdio.h>
#include<stdlib.h>
#define SElemType int
#define Status  int 
#define MAXSIZE 10
#define OK 1; 
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}Stack,*SqStack;

Status InitStack(SqStack S) {
	S->base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	if (!S->base)
		exit(-1);
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return OK;
}//��ʼ��һ��ջ������ռ�

Status DestoryStack(SqStack S) {
	if (!S)
		exit(0);
	free(S);
}

Status ClearStack(SqStack S) {
	if (S->top - S->base == 0)
		exit(0);
	free(S->base);
	//��ջ�ÿ�
}

Status StackEmpty(SqStack S) {
	if (!S->base)
		exit(-1);
	if (S->top - S->base == 0)
		return 1;
	else
		return 0;
	//�ж�ջ�Ƿ�Ϊ��
}

int StackLength(SqStack S) {
	if (!S->base)
		exit(-1);
	return S->top - S->base;
	//����ջ�ĳ���
}

SElemType GetTop(SqStack S) {
	int len = StackLength(S);
	if (len == 0)
		exit(-1);
	else
		return *(S->base + len);
	//����ջ��Ԫ��
}

Status Push(SqStack S,SElemType e) {printf("here");
	if (S->top - S->base >= MAXSIZE)
		exit(-1);
	*(S->base + StackLength(S)) = e;
	S->top++;
	return OK;
	//ѹջ
}

SElemType Pop(SqStack S) {
	int len = StackLength(S);
	if (!len)
		return -1;
	SElemType p = *(S->base + len);
	S->top--;
	return p;
	//��ջ
}

//Status StackTraverse(SqStack S,void (*Func)(SElemType e) {
//	if (!S->base)
//		return -1;
//	
//	////����ջ����ÿ��Ԫ��ʹ�ú���
//}

void Print(SqStack S) {
	SElemType* p = S->base;
	if (!S->base)
		exit(-1);
	printf("ջ��Ԫ�أ�\n");
	for (; p < S->top;) {
		printf("%d\t", *p);
		p++;
	}
	printf("\n");
}



int main() {
	Stack S;
	InitStack(&S);
	Print(&S);
	Push(&S, 5);
	Push(&S,7);
	Print(&S);
	DestoryStack(&S);




	return 0;
}
