#include<stdio.h>
#include<stdlib.h>
#define status int
#define OK 1
typedef struct {
	int* base, *top;
	int stacksize;
	int len;
}Stack, * SqStack;

status InitStack(SqStack S) {
	S->base = (int*)malloc(20 * sizeof(int));
	if (!S->base)
		exit(-1);
	S->top = S->base;
	S->stacksize = 20;
	S->len = 0;
	return OK;
}//初始化栈 

status DestoryStack(SqStack S) {
	if (!S->base)
		exit(-1);
	free(S->base);
	S->base = NULL;
	S->top = S->base;
	S->len = 0;
	S->stacksize = 0;
}//销毁栈 

status Push(SqStack S, int e) {
	if (S->len == S->stacksize)
		exit(-1);
	*(S->top) = e;
	S->top++;//printf("here") ;
	S->len++;
	return OK;
}//压栈 

int Pop(SqStack S) {
	if (S->len == 0)
		exit(-1);
	int  a = *(S->base + S->len);
	S->top--;
	S->len--;
	return a;
}//弹栈 

void Print(SqStack S){
	while((S->top)-->S->base){
		printf("%d\t",*S->top);
	}
	printf("\n");
}//按照出栈顺序打印栈内元素。 

status TrSF(int value, int weight) {
	SqStack S;
	InitStack(S);
	int quot=value;
	int remain;
	while (quot) {
		remain = quot % weight;
		quot /= weight;
		Push(S, remain);
	}
	Print(S);
	DestoryStack(S); 
	return OK;
}//数制转换计算函数，参数(十进制数，权值) 

int main() {
	int value,weight;
	scanf("%d %d",&value,&weight);
	TrSF(value,weight);
	return 0;
}
