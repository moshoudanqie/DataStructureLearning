/*
1.为了操作方便，通常top指示真正的栈顶元素之上的下标位置
2.空栈标志：top-base=0
3.栈满标志：top-base = size
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
}//初始化一个栈，分配空间

Status DestoryStack(SqStack S) {
	if (!S)
		exit(0);
	free(S);
}

Status ClearStack(SqStack S) {
	if (S->top - S->base == 0)
		exit(0);
	free(S->base);
	//将栈置空
}

Status StackEmpty(SqStack S) {
	if (!S->base)
		exit(-1);
	if (S->top - S->base == 0)
		return 1;
	else
		return 0;
	//判断栈是否为空
}

int StackLength(SqStack S) {
	if (!S->base)
		exit(-1);
	return S->top - S->base;
	//返回栈的长度
}

SElemType GetTop(SqStack S) {
	int len = StackLength(S);
	if (len == 0)
		exit(-1);
	else
		return *(S->base + len);
	//返回栈顶元素
}

Status Push(SqStack S,SElemType e) {printf("here");
	if (S->top - S->base >= MAXSIZE)
		exit(-1);
	*(S->base + StackLength(S)) = e;
	S->top++;
	return OK;
	//压栈
}

SElemType Pop(SqStack S) {
	int len = StackLength(S);
	if (!len)
		return -1;
	SElemType p = *(S->base + len);
	S->top--;
	return p;
	//弹栈
}

//Status StackTraverse(SqStack S,void (*Func)(SElemType e) {
//	if (!S->base)
//		return -1;
//	
//	////遍历栈，对每个元素使用函数
//}

void Print(SqStack S) {
	SElemType* p = S->base;
	if (!S->base)
		exit(-1);
	printf("栈内元素：\n");
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
