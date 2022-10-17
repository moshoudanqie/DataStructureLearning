/*静态链表利用结构体数组来实现链表，便于在高级语言中没有指针的情况
下实现链表，这种存储结构仍需要预先分配一个很大的内存空间*/
/*
因为静态链表不能扩展内存，所以必须刚开始init一个很大的内存
通常，备用链表的表头位于数组下标为 0（L[0]） 的位置，而数据链表的表头位于数组下标为 1（L[1]）的位置
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
}component,StLinkList[SIZE];//定义结点，和节点指针

status ListInit(StLinkList L) {
	int i;
	for (i = 0; i < SIZE - 1; i++) {
		L[i].cur = i + 1;
	}
	L[i - 1].cur = 0;
	//初始化
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
	//生成一个链表，储存输入的数据
}

status ListInsert(StLinkList L, int i, Elemtype e) {
	//插入元素
}

status ListDelete(StLinkList L, int i, Elemtype* x) {
	//删除元素
}

int Malloc_SL(StLinkList L) {
	int i = L[0].cur;
	if (L[0].cur)
		L[0].cur = L[i].cur;
	return i;//这地方return的如果是0的话会不会改写链表中的最后一个元素  A:储存数据时不会用到0节点，其他函数会判断分配的下表是否为0再使用
	//分配空间
}

void Free_SL(StLinkList L,int k) {
	L[k].cur = L[0].cur;
	L[0].cur = k;
	//释放空间
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




