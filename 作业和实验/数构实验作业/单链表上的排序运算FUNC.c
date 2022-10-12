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
	int i ,count = 0, num;//count��¼������ĸ�����num�����ڲ�ѭ����
	Lnode *p, *q, *tail;//��������ָ�룬����ð������
	p = L;
	while(p->next != NULL)//��������ĸ���
	{
		count++;//ע�͢�
		p = p->next;
	}
	for(i = 0; i < count - 1; i++)//���ѭ����������ð������һ��
	{
		num = count - i - 1;//��¼�ڲ�ѭ����Ҫ�Ĵ�����������ð������һ����
		q = L->next;//��qָ���һ�����
		p = q->next;//��pָ���һ�����
		tail = L;//��tailʼ��ָ��qǰһ����㣬���㽻����Ҳ�����������һ������
		while(num--)//�ڲ�ѭ�� ����������ð������һ��
		{
			if(q->data > p->data)//����ý���ֵ���ں�һ����㣬�򽻻�
			{
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;//ע�͢�
			q = tail->next;//ע�͢�
			p = q->next;//ע�͢�
		 }
	}
}
*/