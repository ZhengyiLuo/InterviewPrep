#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	node *next;
}node;
typedef node *LinkList;
node *p, *q, *r, *head, *L, *L1;
LinkList build()   //������β�巨
{
	int i;
	head = new(node);
	p = head;
	for (i = 1; i <= 5; i++)
	{
		p->next = new(node);
		p->next->data = i + 'a' - 1;         // ��һ�����ֵΪ�ַ�a
		p = p->next; //��ָ�����Pָ���һ�����
	}
	p->next = NULL; //������β����ָ����Ҫ�ÿգ�
	return(head);
}

void display(LinkList L)
{
	p = L->next;
	while (p != NULL)    //��ָ�벻��ʱѭ������������ͷ���������
	{
		printf("%c  ", p->data);
		p = p->next;                              //��ָ�벻�ϡ�˳�����ϡ�
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



