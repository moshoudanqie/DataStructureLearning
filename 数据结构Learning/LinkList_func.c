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
}//��������һ������

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
}//�������i��Ԫ�ز���e 

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
	printf("��ɾ����Ԫ���ǣ�%d\n",d->data);
	free(d);
	return OK;
} 
status CleanList(LinkList L){
	//���List 
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
//	free(L);//��ô��L��ֵΪNULL 
//	return ;
//}

LinkList MergeList(LinkList La,LinkList Lb,LinkList Lc){
	
	//�ϲ��������������� 
}

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

	//ð������ 
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
}//��ӡ����Ԫ��
 
int main() {
	LinkList L;
	L = CreatList(5);
	Print(L);
	InsertList(L,3,9);
	Print(L);
	DeleteList(L,5);
	BubbleSort(L);
	Print(L);
//	DestroyList(L);
	free(L);
	return 0;

}
