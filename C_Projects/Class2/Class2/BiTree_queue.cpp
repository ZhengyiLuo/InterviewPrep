#include <iostream>
#include <queue>

using namespace std;

struct BiNode
{
	char data;
	BiNode *lchild, *rchild;
};
typedef BiNode *BiTree;

int CreateBiTree(BiTree &T, const char *s1, const char *s2, int len)
{
	if (len <= 0)
	{
		T = NULL;
		return 1;
	}
	else
	{
		T = new BiNode;
		T->data = *s1;
		int i;
		for (i = 0; i<len; i++) if (s2[i] == *s1) break;
		CreateBiTree(T->lchild, s1 + 1, s2, i);
		CreateBiTree(T->rchild, s1 + i + 1, s2 + i + 1, len - (i + 1));
	}
	return 1;
}

int DestroyBiTree(BiTree &T)
{
	if (T == NULL) return 1;
	DestroyBiTree(T->lchild);
	DestroyBiTree(T->rchild);
	delete T;
	T = NULL;
	return 1;
}

int ATraverse(BiTree &T)
{
	if (T == NULL) return 1;
	ATraverse(T->lchild);
	ATraverse(T->rchild);
	cout << T->data;
	return 1;
}

int LevelTraverse(BiTree &T)
{
	if (T == NULL) return 1;
	queue<BiNode *> Q;
	Q.push(T);
	while (!Q.empty())
	{
		BiNode *p = Q.front(); Q.pop();
		cout << p->data;
		if (p->lchild != NULL) Q.push(p->lchild);
		if (p->rchild != NULL) Q.push(p->rchild);
	}
	return 1;
}

//int main()
//{
//	char a[2000], b[2000];
//	while (cin >> a >> b)
//	{
//		BiTree T;
//		int count = 0;
//		int n;
//		for (n = 0; a[n] != '\0'; n++);
//		CreateBiTree(T, a, b, n);
//		ATraverse(T);
//		cout << " ";
//		LevelTraverse(T);
//		cout << endl;
//		DestroyBiTree(T);
//	}
//}