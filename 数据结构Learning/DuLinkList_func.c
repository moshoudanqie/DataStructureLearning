#include<stdio.h>
#include<stdlib.h>
#define Elemtype int

typedef struct DuLNode{
	Elemtype data;
	struct DuLNode* prior,* next;
}DuLNode,*DuLinkList;		//定义双向链表节点结构体

DuLinkList MakeNode(Elemtype e) {
	//make一个节点
}

void FreeNode(DuLinklist p) {
	//销毁一个节点
}

status Append(DuLinkList L, DuLinkList s) {
	//append一个元素
}

int LocateElem() {

}

DuLinkList CreatList(int n) {

}	//创建一个双向链表

status InsertList() {
	//插入一个元素
}

status DeleteList() {
	//删除指定元素
}

status CleanList() {
	//清空
}

void BubbleSort() {
	//冒泡排序
}

DuLinkList MergeList() {
	//合并
}

status GetElem() {
	//查阅元素
}

status LocateElem() {
	//定位元素
}

