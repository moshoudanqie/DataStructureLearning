/*��̬�������ýṹ��������ʵ�����������ڸ߼�������û��ָ������
��ʵ���������ִ洢�ṹ����ҪԤ�ȷ���һ���ܴ���ڴ�ռ�*/
/*
��Ϊ��̬��������չ�ڴ棬���Ա���տ�ʼinitһ���ܴ���ڴ�
ͨ������������ı�ͷλ�������±�Ϊ 0��L[0]�� ��λ�ã�����������ı�ͷλ�������±�Ϊ 1��L[1]����λ��
*/
#include<stdio.h>
#include<stdlib.h>
#define Elemtype int
#define status int
#define ERROR 0
#define OK 1
#define SIZE 20

typedef struct {
	Elemtype data;
	int cur;
}component,StLinkList[SIZE];//�����㣬�ͽڵ�ָ��

status ListInit(StLinkList L) {
	int i;
	for (i = 0; i < SIZE - 1; i++) {
		L[i].cur = i + 1;
	}
	L[i - 1].cur = 0;
	//��ʼ��
}

void ListCreat(StLinkList L,int n) {
	if (n <= 0)
		exit(-1);
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%d", &L[i].data);
	}
	L[0].cur = L[n].cur;
	L[n].cur = 0;
	//����һ�������������������
}

status ListInsert(StLinkList L, int i, Elemtype e) {
	//����Ԫ��
}

status ListDelete(StLinkList L, int i, Elemtype* x) {
	//ɾ��Ԫ��
}

int Malloc_SL(StLinkList L) {
	int i = L[0].cur;
	if (L[0].cur)
		L[0].cur = L[i].cur;
	return i;//��ط�return�������0�Ļ��᲻���д�����е����һ��Ԫ��  A:��������ʱ�����õ�0�ڵ㣬�����������жϷ�����±��Ƿ�Ϊ0��ʹ��
	//����ռ�
}

void Free_SL(StLinkList L,int k) {
	L[k].cur = L[0].cur;
	L[0].cur = k;
	//�ͷſռ�
}

void Print(StLinkList L) {
	int i = 1;
	while (i) {
		printf("%d\t", L[i].data);
		i = L[i].cur;
	}
	printf("\n");
}

int main() {


}




