#include<stdio.h>
#include<stdlib.h>
#define Elemtype int
#define status int
#define INITSIZE 5
#define LISTINCREMENT 10
#define ERROR -1
#define OK 1
typedef struct {
	Elemtype* elem;
	int length;
	int listsize;
}Sqlist;

status InitList(Sqlist* L) {
	L->elem = (Elemtype*)malloc(INITSIZE * sizeof(Elemtype));
	if (!L->elem)
		return ERROR;
	L->length = 0;
	L->listsize = INITSIZE;
	return OK;
}//初始化一个顺序表

status CreatList(Sqlist* L, int len) {

	while (len > L->listsize) {
		Elemtype* newbase = (Elemtype*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(Elemtype));
		if (!newbase)
			return ERROR;
		L->elem = newbase;

		L->listsize += LISTINCREMENT;
	}
	for (int i = 0; i < len; i++) {
		scanf("%d", &L->elem[i]);
	}
	L->length = len;
	return OK;
}//创建一个顺序表 

status DistroyList(Sqlist* L) {
	if (L->elem != NULL) {
		free(L->elem);
		L->elem = NULL;
		L->length = 0;
		L->listsize = 0;
		printf("此顺序表已成功销毁");
		return OK;
	}
	return ERROR;
}//销毁一个指定顺序表



status ListInsert(Sqlist* L, int i, Elemtype x) {

	if (i<1 || i > L->length + 1)
		return ERROR;
	if (L->length >= L->listsize) {
		Elemtype* newbase = (Elemtype*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(Elemtype));
		if (!newbase)
			return ERROR;
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	int j = L->length;
	while (j-- >= i) {
		L->elem[j + 1] = L->elem[j];//这里是否必须用指针操作
	}
	L->elem[i - 1] = x;
	L->length++;
	return OK;
}//在顺序表的i位置插入元素

status ListDelete(Sqlist* L, int i, Elemtype* e) {
	if (i <= 0 || i > L->length)
		return ERROR;
	Elemtype* p = &L->elem[i - 1];
	*e = *p;
	while (p < &L->elem[L->length - 1]) {
		*p = *(p + 1);
		p++;
	}
	*p = 0;
	L->length--;
	printf("删除的元素值为：%d\n", *e);
	return OK;
} //从顺序表中删除一个指定元素

void ElemSearch(Sqlist* L, Elemtype x) {
	int index = 0;
	for (int i = 0; i < L->length; i++) {
		if (L->elem[i] == x) {
			index = i+1;
			break;
		}
	}
	if (index == 0)
		printf("表内没有你要找到元素。\n");
	else if(index >0) 
		printf("该元素在表中的索引为：%d\n", index);
}//查找元素位置

//status ElemMatch(Sqlist* L){}
////返回表中所有与e满足compares函数的元素的位序

status BubbleSort(Sqlist* L) {
	for (int i = 0; i < L->length - 1; i++) {
		for (int j = 0; j < L->length - i - 1;j++) {
			if (L->elem[j] > L->elem[j + 1]) {
				Elemtype temp=L->elem[j];
				L->elem[j] = L->elem[j + 1];
				L->elem[j + 1] = temp;
			}
		}
	}

}//冒泡排序

status ListMerge(Sqlist* La, Sqlist* Lb, Sqlist* Lc) {
	BubbleSort(La);
	BubbleSort(Lb);
	Elemtype* pa = La->elem;
	Elemtype* pb = Lb->elem;
	Elemtype* pa_last = pa+La->length-1;
	Elemtype* pb_last = pb+Lb->length-1;
	Lc->listsize = La->length + Lb->length;
	Lc->elem = (Elemtype*)malloc(Lc->listsize * sizeof(Elemtype));
	if(!Lc->elem)
	return ERROR;
	Elemtype* pc = Lc->elem;
	while(pa<=pa_last&&pb<=pb_last){
		if(*pa<=*pb){
			*pc = *pa;
			pa++;
			pc++;
		}
		else{
			*pc = *pb;
			pb++;
			pc++;
		}
	}
	while(pa<=pa_last)
	*pc++ = *pa++;
	while(pb<=pb_last)
	*pc++ = *pb++;
	Lc->length = Lc->listsize;
}//顺序表合并；

void ListTraveser(Sqlist* L,void (*Plus)(int *value)) {
	for (int i = 0; i < L->length; i++) {
		Plus(&L->elem[i]);
	}	
}//对表中的每个元素调用函数
void Plus(int* value) {
	(*value)++;
}

void Print(Sqlist * L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d\t", L->elem[i]);
	}
	printf("\n");
}



int main() {
	Sqlist La,Lb,Lc;
	Sqlist* p = &La,*q = &Lb;
	Elemtype backE;
	InitList(p);
	InitList(q);
	CreatList(p, 10);
	CreatList(q,5);
	ListMerge(p,q,&Lc);
//	ListDelete(p, 2, &backE);
//	ElemSearch(p, 4);
//	BubbleSort(p);
	//	ListInsert(p,1,3);
	Print(&Lc);
	ListTraveser(&Lc, Plus);
	Print(&Lc);
	free(p->elem);
	free(q->elem);
	free(Lc.elem);
	return 0;
}
