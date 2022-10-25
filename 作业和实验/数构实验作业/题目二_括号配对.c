#include<stdio.h>
#include<stdlib.h>
#define Status int
#define OK 3
#define ERROR -1
typedef struct {
	char* base, * top;
	int stacksize;
	int len;
}stack,*SqStack;

Status InitStack(SqStack S) {
	S->base = (char*)malloc(10 * sizeof(char));
	if (!S->base)
		return ERROR;
	S->top = S->base;
	S->stacksize = 10;
	S->len = 0;
	return OK;
}//初始化栈

Status DestoryStack(SqStack S) {
	if (!S->base)
		exit(-1);
	free(S->base);
	S->base = NULL;
	S->len = 0;
	S->stacksize = 0;
	return OK;
}//销毁表

Status Push(SqStack S,char e) {
	if (S->len == S->stacksize)
		return ERROR;
	*S->top = e;
	S->top++;
	S->len++;
	return OK;
}

Status Pop(SqStack S) {
	if (S->len <= 0)
		return ERROR;
	S->top--;
	*S->top = '0';
	S->len--;
	return OK;
}

void Print(SqStack S){
	if(!S->base)
	exit(-1);
	char* p = S->base;
	for(p;p<S->top;){
		printf("%c\t",*p++);
	}
	printf("\n");
}


Status Match(char exp[]) {
	stack LChars;
	InitStack(&LChars);
	char* s=exp;
	do {
		if (*s == '(' || *s == '[' || *s == '{') {
			Push(&LChars, *s);
		}
		else if (*s == ')') {
			if(LChars.len<=0)
			return 0;
			if (*(LChars.top - 1) == '(')
				Pop(&LChars);
		}
		else if (*s == ']') {
			if(LChars.len<=0)
			return 0;
			if (*(LChars.top - 1) == '[')
				Pop(&LChars);
		}
		else if (*s == '}') {
			if(LChars.len<=0)
			return 0;
			if (*(LChars.top - 1) == '{')
				Pop(&LChars);
		}
		s++;
	} while (*s != '\0');
	int status = LChars.len == 0 ? 1 : 0;
	return status;
	DestoryStack(&LChars);

}

int main() {
	char exp[20];
	scanf("%s", &exp); 
	int bool = Match(exp);
	if(bool==1)
	printf("yes");
	else if(bool==0)
	printf("no");
	return 0;
}
