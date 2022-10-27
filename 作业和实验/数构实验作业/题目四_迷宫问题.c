#include<stdio.h>
#include<stdlib.h>
#define M 10
#define N 10
#define OVERFLOW -2
#define OK 1;
#define status int
typedef struct step {
	int X;//横坐标
	int Y;//纵坐标
	int dir;//方向
}Step;

typedef struct stack {
	Step* base, *top;
	int stacksize;
}Stack;

status InitStack(Stack *S) {
	int size = M * N - (M + N);
	S->base = (Step*)malloc(size * sizeof(Step));
	if (!S->base)
		exit(-2);
	S->top = S->base;
	S->stacksize = size;
	return OK;
	//初始化栈
}

status Push(Stack* S,Step e) {
	if (S->top - S->base == S->stacksize)
		return OVERFLOW;
	*(S->top) = e;
	S->top++;
	return OK;
}
status Pop(Stack *S,int *BackDir) {
	if (S->top == S->base)
		return OVERFLOW;
	S->top--;
	*BackDir = (S->top - 1)->dir;
	return OK;
}
void CAB(Stack* S,int *b){
	Step e = *(S->top-1);
	Step* p = S->base;
	while(p<S->top-1){
		if(p->X==e.X&&p->Y==e.Y){
			break;
		}
		p++;
		
	}
	//返回第一次走的方向 
	if(p==S->top-1)
	return ;
	else{
		while(S->top>p){
			Pop(S,b);
		}
	}
}
void DestoryStack(Stack* S) {
	free(S->base);
	S->base = NULL;
	S->top = S->base;
	S->stacksize = 0;
}
status Print(Stack S) {
	if (S.base == NULL)
		return OVERFLOW;
	Step* p = S.base;
	while (p != S.top) {
		printf("(%d,%d,%d)\t", p->X, p->Y, p->dir);
		p++;
	}
	return OK;
}

void MakeMaze(int maze[M][N], int m, int n) {
	int i,j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			maze[i][j] = 1;
		}
	}
	printf("输入'E'停止：\n"); 
	while(1){
		int count = scanf("%d %d",&i,&j);
		if(count!=2)
			break;
		if(i>=m||j>=n||i<0||j<0) 
			break;
		maze[i][j]= 0;
	}
}
void PrintMaze(int maze[][N], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d  ", maze[i][j]);
		}
		printf("\n");
	}
}
void RunMazes() {//1.右 2.下 3.左 4.上
	int maze[M][N];
	MakeMaze(maze, M, N);
	PrintMaze(maze, M, N);
	Stack route;
	InitStack(&route);
	Step p = { 0,0,0 };
	int BackDir=0;
	Step* T = route.top; 
	int count = 0;
	do {
		if(!count)	
			Push(&route,p);
		CAB(&route,&BackDir);
		count=0;
		T = route.top-1;
		//下面操作针对栈顶元素
		if (maze[T->X][T->Y + 1]==0) {
			
			if((T-1)->dir==3);
			else if (BackDir == 1)
				BackDir = 0;
			else {
				p.X = T->X;
				p.Y = T->Y + 1;
				T->dir = 1;
			//	Push(&route, p);
				BackDir = 0;
			
				continue;
			}
		}
		if (maze[T->X + 1][T->Y]==0) {
			if((T-1)->dir==4);
			else if (BackDir == 2)
				BackDir = 0;
			else {
				p.X = T->X + 1;
				p.Y = T->Y;
				T->dir = 2;
				BackDir = 0;
				/*将p赋值为下边元素
				p.dir = 2;
				回退元素置零；*/
				continue;
			}
		}
		if (maze[T->X][T->Y - 1]==0) {
			if((T-1)->dir==1);
			else if (BackDir == 3)
				BackDir = 0;
			else {
				p.X = T->X;
				p.Y = T->Y - 1;
				T->dir = 3;
				BackDir = 0;
				/*将p赋值为右边元素
					p.dir = 3;
				回退元素置零；*/
				continue;
			}
		}
		if (maze[T->X - 1][T->Y]==0) {
			if((T-1)->dir==2);
			else if (BackDir == 4)
				BackDir = 0;
			else {
				p.X = T->X - 1;
				p.Y = T->Y;
				T->dir = 4;	
				BackDir = 0;
				/*将p赋值为上边元素
					p.dir = 4;
				回退元素置零；*/
				continue;
			}
		}
		
		//回退
		Pop(&route, &BackDir);
		count=1;
	}
	while (T->X != 8 || T->Y != 7);
	Print(route);
	DestoryStack(&route);
}

int main() {
	RunMazes();
	return 0;
}
