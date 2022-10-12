#include<stdio.h>
#include<stdlib.h>
#include"单链表上的排序运算.h"
int main() {
	LinkList list = ListCreat();
	Print(list);
	BubbleSort(list);
	Print(list);
	free(list);
}