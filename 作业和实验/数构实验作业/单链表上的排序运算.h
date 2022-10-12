#pragma once
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * LinkList;
LinkList ListCreat();
void BubbleSort(LinkList);
void Print(LinkList L);
