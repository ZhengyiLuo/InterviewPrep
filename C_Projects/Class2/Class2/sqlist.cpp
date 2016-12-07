#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW   0
#define ERROR   0
#define OK  1
#define LIST_INIT_SIZE   100
#define LISTINCREMENT  10
typedef  struct {
	int     key;
}ElemType;
ElemType *newbase, *q, *p;
typedef  struct {
	ElemType   *elem;
	int     length;
	int     listsize;
}SqList;
SqList  L, P;
int InitList_SqList(SqList &L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int ListInsert_sq(SqList &L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length >= L.listsize)  {
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i]);
	for (p = &(L.elem[L.length]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}

int Partition(SqList &L, int low, int high)
{
	L.elem[0] = L.elem[low];
	int pivotkey = L.elem[low].key;
	while (low < high){
		while (low<high && L.elem[high].key >= pivotkey) --high;
		L.elem[low] = L.elem[high];
		while (low<high && L.elem[low].key <= pivotkey) ++low;
		L.elem[high] = L.elem[low];
	}
	L.elem[low] = L.elem[0];
	return low;
}

void QSort(SqList &L, int low, int high)
{
	if (low<high){
		int pivot = Partition(L, low, high);
		QSort(L, low, pivot - 1);
		QSort(L, pivot + 1, high);
	}
}

void QuickSort(SqList &L)
{
	QSort(L, 1, L.length);
}

int single_serch(SqList &L, int key_x)
{
	for (int i = 1; i <= L.length; i++)
	{
		if (L.elem[i].key == key_x)
			return(i);
	}
	return(0);
}

int bisearch(SqList &L, int key_x) //only for ordered seqlist
{
	int low, high, mid;
	low = 1;
	high = L.length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (L.elem[mid].key == key_x)
			return(mid);
		else if (L.elem[mid].key<key_x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return(0);
}

void delzeros(SqList &L)
{
	int i, j;
	i = 1;
	while (i<L.length&&L.elem[i].key != 0) i++;
	j = i + 1;
	if (i<L.length)
	{
		while (j <= L.length)
		{
			while (j <= L.length&&L.elem[j].key == 0) j++;
			if (j>L.length) break;
			while (j <= L.length&&L.elem[j].key != 0)
			{
				L.elem[i] = L.elem[j];
				L.elem[j].key = 0;
				i++; j++;
			}
		}
	}
}

int match_BP(SqList &L, SqList &P, int pos)
{
	int i, j, ip;
	ip = pos;
	while (ip <= L.length - P.length + 1)
	{
		i = ip; j = 1;
		while ((j <= P.length) && (L.elem[i].key == P.elem[j].key))
		{
			i++; j++;
		}
		if (j>P.length)
			return(ip);
		else ip++;
	}
	return(0);
}

int match_KMP(SqList &L, SqList &P, int pos)
{
	int i, j, ip;
	ip = pos;



	while (ip <= L.length - P.length + 1)
	{
		i = ip; j = 1;
		while ((j <= P.length) && (L.elem[i].key == P.elem[j].key))
		{
			i++; j++;
		}
		if (j>P.length)
			return(ip);
		else;
	}
	return(0);
}

//void main()
//{
//	ElemType x;
//	int k, m, n, i,j = 0,num, a[100] = {1,2,3,5,6,0,0,7,4,3,4,0,5,6,0,2,4,0,6,4,0,0,7,8,0}, store;
//	m = InitList_SqList(L);
//	n = InitList_SqList(P);
//	printf("please enter the num  ");
//	scanf("%d", &num);
//	for (i = 1; i <= num; i++)
//	{
//		x.key = a[i];
//		ListInsert_sq(L, i, x);
//	}
//	for (i = 1; i <= L.length; i++)
//	{
//		printf("%d  ", L.elem[i].key);
//	}
//	printf("\n");
//
//	for (i = 1; i <= num; i++){
//		if (L.elem[i].key == 0){
//			store = i;
//			while (L.elem[i+1].key == 0)
//			{
//				i++;
//			}
//
//			for (j = 0; j < num - i && L.elem[i+1].key !=0; j++, store++,i++)
//			{
//				L.elem[store].key = L.elem[i + 1].key;
//			}
//			L.length--;
//		}
//	}
//
//	for (i = 1; i <= L.length; i++)
//	{
//		printf("%d  ", L.elem[i].key);
//	}
//	printf("\n");
//
//	
//
//	//printf("match position is %d  ", match_BP(L, P, 3));
//	system("pause");
//}



