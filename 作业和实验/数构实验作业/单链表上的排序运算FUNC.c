#include<stdio.h>
#include<stdlib.h>
#define status int
#define OK 1
#define ERROR 0
typedef struct Lnode{
	int data;
	struct Lnode* next;
}Lnode,*LinkList;

 LinkList ListCreat() {
	 LinkList L = (LinkList)malloc(sizeof(Lnode));
	 L->next = NULL;
	 while (1) {
		 LinkList s = (LinkList)malloc(sizeof(Lnode));
		 if (s) {
			 scanf("%d", &(s->data));
		 }
		 if (s->data == 0) {
			 break;
		 }
		 else {
			 s->next = L->next;
			 L->next = s;
		 } 
	 }
	 return L;
}


void Print(LinkList L) {

	 LinkList p = L;
	 while (p->next != NULL) {
		 p = p->next;
		 printf("%d\t", p->data);
	 }
	 printf("\n");

 }


void BubbleSort(LinkList L) {
	int count = 0, i;
	LinkList cursor, p, q;
	cursor = L;
	while (cursor->next != NULL) {
		count++;
		cursor = cursor->next;
	}
	for (i = 0; i < count - 1; i++) {
		cursor = L;
		p = cursor->next;
		q = p->next;
		int num = count - i - 1;
		while (num--) {
			if (p->data > q->data) {
				p->next = q->next;
				q->next = p;
				cursor->next = q;
			}
			cursor = cursor->next;
			p = cursor->next;
			q = p->next;
		}
	}
}




/*
void BubbleSort(LinkList L)
{
	int i ,count = 0, num;//count记录链表结点的个数，num进行内层循环，
	Lnode *p, *q, *tail;//创建三个指针，进行冒泡排序
	p = L;
	while(p->next != NULL)//计算出结点的个数
	{
		count++;//注释①
		p = p->next;
	}
	for(i = 0; i < count - 1; i++)//外层循环，跟数组冒泡排序一样
	{
		num = count - i - 1;//记录内层循环需要的次数，跟数组冒泡排序一样，
		q = L->next;//令q指向第一个结点
		p = q->next;//令p指向后一个结点
		tail = L;//让tail始终指向q前一个结点，方便交换，也方便与进行下一步操作
		while(num--)//内层循环 次数跟数组冒泡排序一样
		{
			if(q->data > p->data)//如果该结点的值大于后一个结点，则交换
			{
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;//注释②
			q = tail->next;//注释②
			p = q->next;//注释②
		 }
	}
}
*/