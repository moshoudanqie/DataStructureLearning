#include<stdio.h>
#include<stdlib.h>
#define Elemtype char
typedef struct tNode {
	Elemtype data;
	struct tNode* parent, *Lchild, *Rchild;
}tNode,*BiTree;

//BiTree CreatTree() {
//	int data;
//	int temp;
//	BiTree T;
//	scanf
//}


int travel(BiTree T) {
	if (!T)
		return;
	printf("%d", T->data);
	if (T->Lchild)
		travel(T->Lchild);
	if (T->Rchild)
		travel(T->Rchild);
}//先序遍历

int travel(BiTree T) {
	if (!T)
		return;
	else {
		travel(T->Lchild);
		printf("%d", T->data);
		travel(T->Rchild);
	}
}//中序遍历

int travel(BiTree T) {
	if (!T)
		return;
	else {
		travel(T->Lchild);
		travel(T->Rchild);
		printf("%d", T->data);
	}
}//后续遍历
//以上三种是递归算法

int travel2(BiTree T) {
	tNode* p, *q;
	InitStack(S);
	p = T;
	while (p || !EmptyStack(S)) {
		if (p) {
			Push(S, p);
			p = p->Lchild;
		}
		else {
			q = Pop(S);
			printf("%d", q->data);
			p = q->Rchild;
		}
	}
	return OK;
}//六六六，非递归实现中序遍历

status travel3(BiTree T) {
	InitQueue(Q);
	if (!T)
		return;
	else(
		EnQueue(Q, T);
		while (!QuEmpty(Q) {
			tNode* p = OutQueue(Q);
			printf("%d", p->data);
			if (p->Lchild)
				EnQueue(Q, p->Lchild);
			if (p->Rchild)
				EnQueue(Q, p->Rchild);
		}
		return OK;
		)
}

