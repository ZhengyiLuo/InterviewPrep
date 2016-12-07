#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	node *next;
}node;
typedef node *LinkList;
node *p, *q, *r, *head, *L, *L1;
LinkList build()   //单链表尾插法
{
	int i;
	head = new(node);
	p = head;
	for (i = 1; i <= 5; i++)
	{
		p->next = new(node);
		p->next->data = i + 'a' - 1;         // 第一个结点值为字符a
		p = p->next; //让指针变量P指向后一个结点
	}
	p->next = NULL; //单链表尾结点的指针域要置空！
	return(head);
}

void display(LinkList L)
{
	p = L->next;
	while (p != NULL)    //当指针不空时循环（仅限于无头结点的情况）
	{
		printf("%c  ", p->data);
		p = p->next;                              //让指针不断“顺藤摸瓜”
	}
	printf("\n");
}

void reverse(LinkList &L)
{
	p = L->next;
	if (p == NULL || p->next == NULL)
	{
		printf("No reverse needed!\n");
		return;
	}
	q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	L->next = p;
}

//void main()
//{
//	L1 = build();
//	display(L1);
//	reverse(L1);
//	display(L1);
//	system("pause");
//}



