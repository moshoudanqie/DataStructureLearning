#include<stdio.h>
#include<stdlib.h>
#define Elemtype int
#define status int
#define ERROR 0
#define OK 1
typedef struct Lnode {
	Elemtype data;
	struct Lnode* next;
}Lnode,*LinkList;

LinkList CreatList(int len) {
	LinkList L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	for (int i = 0; i < len; i++) {
		LinkList s = (LinkList)malloc(sizeof(Lnode));
		if (!s)
			break;
		scanf("%d", &(s->data));
		s->next = L->next;
		L->next = s;
	}
	return L;
}//倒序输入一个链表

status InsertList(LinkList L, int i, Elemtype e) {
	LinkList p = L;
	int j = 0;
	while (p&&j<i-1) {
		p = p->next;
		j++;
	}
	if (!p || j > i-1)
		return ERROR;
	LinkList s = (LinkList)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}//在链表第i个元素插入e 

status DeleteList(LinkList L,int i){
	LinkList p = L;
	int j = 0;
	while(p && j<i-1){
		p = p->next;
		j++;
	}
	if(!p||j>i-1)
	return ERROR;
	LinkList d = p->next;
	p->next = p->next->next;
	printf("你删除的元素是：%d\n",d->data);
	free(d);
	return OK;
} 
status CleanList(LinkList L){
	//清空List 
	if(!L)
	return ERROR;
	LinkList head = L->next;
	while(head){
		LinkList q = head;
		head = head->next;
		free(q);
	}
	L->next = NULL;
	return OK;
}

//status DestroyList(LinkList L){
//	if(!L)
//	return ERROR;
//	LinkList p = L;
//	while(p){
//		LinkList q = p;
//		p = p->next;
//		free(q);
//	}
//	free(L);//怎么将L赋值为NULL 
//	return ;
//}

void BubbleSort(LinkList L){
	int length=0,i;
	LinkList cursor = L->next,p,q;
	while(cursor){
		length++;
		cursor = cursor->next;
	}
	for(i = 0;i<length-1;i++){
		int num = length -i-1;
		cursor = L;
		while(num--){
			p = cursor->next;
			q = p->next;
			if(p->data>q->data){
				p->next = q->next;
				q->next = p;
				cursor->next = q;	
			}
			cursor = cursor->next;
		}
	}

	//冒泡排序 
}


LinkList MergeList(LinkList La,LinkList Lb){
	BubbleSort(La);
	BubbleSort(Lb);
	LinkList Lc=La,pc = La;
	LinkList pa = La->next,
			pb = Lb->next;
	while (pa && pb) {
		if (pa->data > pb->data) {
			pc->next = pb;
			pc = pc->next;
			pb = pb->next;
		}
		else {
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
	return Lc;
	//合并两个链表并且排序 
}

void Print(LinkList L){
	if(!L)
	exit(1);
	LinkList p = L->next;
	int j =0;
	while(p!=NULL){
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}//打印链表元素
 
int main() {
	LinkList La,Lb,Lc;
	La = CreatList(5);
	Print(La);
	Lb = CreatList(5);
	Print(Lb);
	Lc = MergeList(La, Lb);
	Print(Lc);
	//InsertList(L,3,9);
	//Print(L);
	//DeleteList(L,5);
	//BubbleSort(L);
	//Print(L);
//	DestroyList(L);
	free(Lc);
	return 0;

}
