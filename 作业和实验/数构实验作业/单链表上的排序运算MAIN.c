#include<stdio.h>
#include<stdlib.h>
#include"�������ϵ���������.h"
int main() {
	LinkList list = ListCreat();
	Print(list);
	BubbleSort(list);
	Print(list);
	free(list);
}