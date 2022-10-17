#include<stdio.h>
#include<stdlib.h>
#define status int
typedef struct player {
	int SrlNum;
	int key;
	struct player* next;
}Player,*CirLinkList;//建立概念模型

CirLinkList CreatCLL(int n) {
	CirLinkList H = (CirLinkList)malloc(sizeof(Player));
	H->next = H;
	CirLinkList p = H;
	for (int i = 0; i < n; i++) {
		CirLinkList s = (CirLinkList)malloc(sizeof(Player));
		s->SrlNum = i+1;
		scanf("%d", &s->key);
		s->next = H;
		p->next = s;
		p = p->next;
	}
	return H;
}

void Append(CirLinkList C,int key) {
	CirLinkList cur = C;
	while (cur->next != C) {
		cur = cur->next;
	}
	CirLinkList p = cur->next;
	cur->next = cur->next->next;
	free(p);
	while (cur->next != cur) {
		while (--key) {
			cur = cur->next;
		}
		key = cur->next->key;
		//更换key值
		printf("%d\t", cur->next->SrlNum);
		CirLinkList s = cur->next;
		cur->next = cur->next->next;
		free(s);
	}
	printf("%d", cur->SrlNum);
	free(cur);
}

void Print(CirLinkList CLL) {
	CirLinkList p = CLL->next;
	while (p!=CLL) {
		printf("%d %d\t", p->SrlNum,p->key);
		p = p->next;
	}
}

int main() {
	CirLinkList C = CreatCLL(7);
	Print(C);
	Append(C,20);
	free(C);
	return 0;
}
//Maybe有点问题但是运行结果是正确的 