#include<stdio.h>
#include<stdlib.h>
typedef struct term {
	float coef;
	int exp;
	struct term* next;
}Term,*Polynomial;

Polynomial CreatPoly() {
	int n;
	scanf("%d", &n);
	Polynomial head = (Polynomial)malloc(sizeof(Term));
	if (!head)
		exit(-1);
	head->coef = 0;
	head->exp = -1;
	head->next = NULL;
	Polynomial p = head;
	for (int i = 0; i < n; i++) {
		Polynomial s = (Polynomial)malloc(sizeof(Term));
		if (!s)
			exit(-1);
		scanf("%f %d", &s->coef, &s->exp);
		s->next = NULL;
		p->next = s;
		p = p->next;
	}
	return head;
}

void SortPoly(Polynomial L) {
	int len=0;
	Polynomial cur = L->next,p,q;
	while (cur) {
		len++;
		cur = cur->next;
	}
	printf("%d\n", len);
	for (int i = 0; i < len - 1; i++) {
		cur = L;
		int num = len - i - 1;
		while (num--) {
			p = cur->next;
			q = p->next;
			if (p->exp > q->exp) {
				cur->next = q;
				p->next = q->next;
				q->next = p;
			}
			cur = cur->next;
		}
	}
}

void Out(Polynomial L) {
	Polynomial p = L->next;
	while (p->next) {
		if (p->coef != 0.0) {
				if (p->exp == 0) {
					printf("%f+", p->coef);
				}
				else
					printf("%fx^%d+", p->coef, p->exp);
		}
		p = p->next;
	}
	printf("%fx^%d\n", p->coef, p->exp);
}

Polynomial PolyAdd(Polynomial La,Polynomial Lb) {
	SortPoly(La);
	SortPoly(Lb);
	Polynomial Pa = La->next;
	Polynomial Pb = Lb->next;
	Polynomial Pc = La;
	Polynomial Lc = La;
	while (Pa && Pb) {
		if (Pa->exp < Pb->exp) {
			Pc->next = Pa;
			Pa = Pa->next;
			Pc = Pc->next;
		}
		else if (Pa->exp > Pb->exp) {
			Pc->next = Pb;
			Pb = Pb->next;
			Pc = Pc->next;
		}
		else if (Pa->exp == Pb->exp) {
			Pc->next = Pa;
			Pa->coef += Pb->coef;
			Pa = Pa->next;
			Pb = Pb->next;
			Pc = Pc->next;
		}
	}
	Pc->next = Pa ? Pa : Pb;
	free(Lb);
	return Lc;
}

Polynomial PolyMinus(Polynomial La,Polynomial Lb) {
	SortPoly(La);
	SortPoly(Lb);
	Polynomial p = Lb->next;
	while(p){
		p->coef = 0-p->coef;
		p = p->next;
	}
	Out(Lb);
	Polynomial Pa = La->next;
	Polynomial Pb = Lb->next;
	Polynomial Pc = La;
	Polynomial Lc = La;
	while (Pa && Pb) {
		if (Pa->exp < Pb->exp) {
			Pc->next = Pa;
			Pa = Pa->next;
			Pc = Pc->next;
		}
		else if (Pa->exp > Pb->exp) {
			Pc->next = Pb;
			Pb = Pb->next;
			Pc = Pc->next;
		}
		else if (Pa->exp == Pb->exp) {
			Pc->next = Pa;
			Pa->coef += Pb->coef;
			Pa = Pa->next;
			Pb = Pb->next;
			Pc = Pc->next;
		}
	}
	Pc->next = Pa ? Pa : Pb;
	free(Lb);
	return Lc;

	//多项式相减
}

int main() {//加减不能同时调用，因为调用其中之一会销毁原来的链表
	Polynomial Pa = CreatPoly();
	Out(Pa);
	Polynomial Pb = CreatPoly();
	Out(Pb);
	//Out(PolyAdd(Pa, Pb));
	Out(PolyMinus(Pa, Pb));
	//SortPoly(P);
	//Out(P);
	return 0;
}


