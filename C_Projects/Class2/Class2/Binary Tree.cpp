//#include<iostream>
//#include <queue>
//using namespace std;
//
//#define TRUE 1
//#define FALSE 0
//#define OK 1
//#define ERROR 0
//#define INFESIBLE -1
//#define MAXQSIZE 100
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT   10
//
//typedef int Status;
//typedef char TElemType;
//typedef enum PointerTag{Link, Thread};
//
//struct BiTNode
//{
//	TElemType data;
//	struct  BiTNode *lchild, *rchild;
//	int LTag, RTag;
//};
//typedef BiTNode *SElemType;
//typedef BiTNode * QElemType;
//
//struct SqQueue{
//	QElemType *base;
//	int front;
//	int rear;
//};
//
//struct SqStack
//{
//	SElemType *base;
//	SElemType *top;
//	int stacksize;
//};
//
//struct HFTNode{
//	int weight;
//	int parent, lchild, rchild;
//};
//
//BiTNode *pre;
//Status InitStack(SqStack &S);
//Status StackLength(SqStack S);
//Status StackEmpty(SqStack S);
//Status Push(SqStack &S, SElemType e);
//Status Pop(SqStack &S, SElemType &);
//Status StackTraverse(SqStack &S, Status(*visit)(SElemType));
//Status GetTop(SqStack &S, SElemType &e);
//Status visit(SElemType c);
//BiTNode *CreatBiTree(BiTNode *&);
//Status PreOrderTraverse(BiTNode *T);
//Status LevelOrderTraverse(BiTNode *T);
//Status InOrderTraverse(BiTNode *T, Status(*Visit)(SElemType e));
//Status InOrderTraverse_Link(BiTNode *T, Status(*Visit)(SElemType e));
//Status PostOrderTraverse(BiTNode *T, Status(*Visit)(SElemType e));
//Status InOrderThreading(BiTNode *&, BiTNode *chain);
//Status InitQueue(SqQueue &Q);
//Status QueueEmpty(SqQueue &Q);
//Status EnQueue(SqQueue &Q, QElemType e);
//Status DeQueue(SqQueue &Q, QElemType &e);
//int QueueLength(SqQueue Q);
//Status GetHead(SqQueue Q, QElemType &e);
//Status QueueTraverse(SqQueue Q, Status(*Visit)(QElemType e));
//void InThreading(BiTNode *p);
//void Select(HFTNode *&, int i, int&, int&);
//void HuffmanCoding(HFTNode *&, char *HC[], int *w, int n);
//Status BackCreatBiTree(char pre[10], char mid[10], BiTNode *&, int len);
//int TreeLengthCal(BiTNode *T);
//
////int main(){
////
////	/*HFTNode *HT;
////	char *HC[100];
////	int n;
////	int a[10] = { 5, 29, 7, 8, 14, 23, 3, 11 };
////	n = 8;
////	HuffmanCoding(HT, HC, a, n);*/
////	unfinished jobs
////
////	BiTNode *T = NULL, *p, *Q = NULL;
////	char pre[10] = { 'A', 'B', 'H', 'F', 'D', 'E', 'C', 'K', 'G' };
////	char mid[10] = { 'H', 'B', 'D', 'F', 'A', 'E', 'K', 'C', 'G' };
////	BackCreatBiTree(pre, mid, Q, 9);
////	/*InOrderThreading(T, Q);
////	InOrderTraverse_Link(T, visit);*/
////	LevelOrderTraverse(Q);
////	CreatBiTree(Q);
////	cout << TreeLengthCal(Q) << endl;
////	cout << endl;
////	cout << endl;
////	PreOrderTraverse(Q);
////	cout << endl;
////	cout << endl;
////	InOrderTraverse(Q, visit);
////	
////	/*CreatBiTree(T);
////	InOrderTraverse(T, visit);*/
////	
////
////	system("pause");
////	return 0;
////}
//
//void HuffmanCoding(HFTNode *(&HT), char *HC[], int *w, int n){
//	int i, s1, s2, start, c, f;
//	HFTNode *p;
//	char cd[100];
//	if (n <= 1) return;
//	int m = n * 2 - 1;
//	HT = (HFTNode*)malloc((m + 1)*sizeof(HFTNode));
//	for (p = HT, i = 1; i <= n; i++, p++, w++)
//		*p = { *w, 0, 0, 0 };
//	for (; i <= m; i++, p++) *p = { 0, 0, 0, 0 };
//	for (i = n + 1; i <= m; i++)
//	{
//		Select(HT, i - 1, s1, s2);
//		HT[s1].parent = i - 1;
//		HT[s2].parent = i - 1;
//		HT[i - 1].lchild = s2;
//		HT[i - 1].rchild = s1;
//		HT[i - 1].weight = HT[s1].weight + HT[s2].weight;
//	}
//
//
//
//	for (i = 0; i < n; i++)
//	{
//
//		for (m = 0, c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent, m++)
//		{
//			if (HT[f].lchild == c) cd[m] = '0';
//			else cd[m] = '1';
//		}
//		cd[m] = '\0';
//		//strcpy(HC[i], cd);
//	    HC[i] = cd;
//		cout << HC[i] << endl;
//		cout << &HC[i] << endl;
//		cout << i << endl;
//	}
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	for (i = 0; i < n; i++)
//	{
//		cout << HC[i] << endl;
//		cout << &HC[i] << endl;
//		cout << i << endl;
//	}
//	return;
//}
//
//void Select(HFTNode *(&HT), int i, int&s1, int&s2){
//	HFTNode *q;
//	int m, min1, min2;
//	q = HT;
//	min1 = 100000;
//	min2 = 100000;
//	for (q = HT, m = 0; m < i; m++)
//	{
//		if (q[m].parent == 0 && q[m].weight < min1){
//			min1 = q[m].weight;
//			s1 = m;
//		}
//	}
//
//	for (q = HT, m = 0; m < i; m++)
//	{
//		if (q[m].parent == 0 && m != s1 && q[m].weight < min2){
//			min2 = q[m].weight;
//			s2 = m;
//		}
//
//	}
//
//}
//
//BiTNode *CreatBiTree(BiTNode *&T){
//	TElemType ch;
//	cout << "Please enter the words" << endl;
//	cin >> ch;
//	if (ch == '-') T = NULL;
//	else{
//		 T = new BiTNode;
//		T->data = ch;
//		CreatBiTree(T->lchild);
//		CreatBiTree(T->rchild);
//	}
//	return T;
//}
//
//Status PreOrderTraverse(BiTNode *T){
//	static int x = 0;
//	if (T != NULL && T->rchild == NULL && T->lchild == NULL)
//	{
//		x++;
//	}
//	if (T){
//		visit(T);
//	    PreOrderTraverse(T->lchild);
//		PreOrderTraverse(T->rchild); 
//	}
//	else {
//		return OK;
//	}
//	return x;
//}
//
//Status InOrderTraverse(BiTNode *T, Status(*Visit)(SElemType e)){
//	SqStack S;
//	BiTNode *p = new BiTNode;
//	InitStack(S);
//	Push(S, T);
//	while (!StackEmpty(S)){ 
//		while (GetTop(S, p) && p) Push(S, p->lchild);
//		Pop(S, p);
//		if (!StackEmpty(S)){
//			Pop(S, p);
//			if (!visit(p))
//				return ERROR;
//			Push(S, p->rchild);
//		}
//	}
//
//	return OK;
//}
//
//Status LevelOrderTraverse(BiTNode *T){
//	SqQueue Q;
//	BiTNode *p;
//	InitQueue(Q);
//	EnQueue(Q, T);
//	while (!QueueEmpty(Q)){
//		DeQueue(Q, p);
//		visit(p);
//		if (p->lchild)
//		EnQueue(Q,p->lchild);
//		if (p->rchild)
//		EnQueue(Q,p->rchild);
//	}
//
//	return OK;
//
//
//}
//
//Status InitStack(SqStack &S){
//
//	S.base = new SElemType;
//	if (!S.base) exit(OVERFLOW);
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;
//	return OK;
//}
//
//Status Push(SqStack &S, SElemType e){
//	if (S.top - S.base >= S.stacksize){
//		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
//		if (!S.base) exit(OVERFLOW);
//		S.top = S.base + S.stacksize;
//		S.stacksize += STACKINCREMENT;
//	}
//	*S.top++ = e;
//	return OK;
//
//}
//
//Status Pop(SqStack &S, SElemType &e){
//	if (S.top == S.base)return ERROR;
//	e = *--S.top;
//	return OK;
//}
//
//Status StackTraverse(SqStack &S, Status(*visit)(SElemType)){
//	if (S.base == S.top) cout << "Empty Stack" << endl;
//	while (S.top>S.base)
//		visit(*S.base++);
//
//	return OK;
//}
//
//Status visit(SElemType c)
//{
//	cout << c->data  << endl;
//	return OK;
//}
//
//Status StackEmpty(SqStack S){
//	if (S.top == S.base)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//Status GetTop(SqStack &S, SElemType &e){
//	if (S.top>S.base)
//	{
//		e = *(S.top - 1);
//		return OK;
//	}
//	else
//		return ERROR;
//}
//
//Status BackCreatBiTree(char pre[10], char mid[10], BiTNode *&T, int len){
//	int i = 0;
//	if (len <= 0){
//		T = NULL;
//		return 0;
//	}
//	else{
//		T = new BiTNode;
//		T->data = *pre;
//		for ( i = 0; i < len; i++)
//			if (*pre == mid[i]) break;
//		BackCreatBiTree(pre+1, mid, T->lchild, i);
//		BackCreatBiTree(pre + i + 1, mid + i + 1, T->rchild, len - (i + 1));
//	}
//	return 0;
//}
//
//Status InOrderTraverse_Link(BiTNode *T, Status(*Visit)(SElemType e)){
//	BiTNode *p = new BiTNode;
//	p = T->lchild;
//	while (p != T){
//		while (p->LTag == Link)p = p->lchild;
//		if (!visit(p)) return ERROR; //如果没有后继访问左子树
//		while (p->RTag == Thread && p->rchild!=T)
//		{
//			p = p->rchild;
//			visit(p);//访问后继
//		}
//		p = p->rchild;
//	}
//
//	return OK;
//
//}
//
//Status InOrderThreading(BiTNode *&T, BiTNode *chain){
//	 
//	T = new BiTNode;
//	T->LTag = Link;
//	T->RTag = Thread;
//	T->rchild = T;
//	if (!chain) T->lchild = T;
//	else{
//		T->lchild = chain;
//		pre = T;
//		InThreading(chain);
//		pre->rchild = T;
//		pre->RTag = Thread;
//	}
//	return OK;
//
//}
//
//void InThreading(BiTNode *p){
//	if (p){
//		if (p->rchild) p->RTag = Link;
//		if (p->lchild) p->LTag = Link;
//		InThreading(p->lchild);
//		if (!p->lchild){
//			p->LTag = Thread;
//			p->lchild = pre;
//		}
//		if (pre&&!pre->rchild){
//			pre->RTag = Thread;
//			pre->rchild = p;
//		}
//		pre = p;
//		InThreading(p->rchild);
//	}
//}
//
//int TreeLengthCal(BiTNode *T){
//	int rchild = 0, lchild = 0;
//	if (T == NULL)
//	{
//		return 0;
//	}
//	lchild = TreeLengthCal(T->lchild);
//	rchild = TreeLengthCal(T->rchild);
//
//	if (lchild > rchild)
//	{
//		return lchild+1;
//	}
//	return rchild+1;
//}
//
//Status InitQueue(SqQueue &Q){
//	Q.base = (QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
//	if (!Q.base) exit(OVERFLOW);
//	Q.front = Q.rear = 0;
//	return OK;
//}
//
//Status EnQueue(SqQueue &Q, QElemType e){
//	if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;
//	Q.base[Q.rear] = e;
//	Q.rear = (Q.rear + 1) % MAXQSIZE;
//	return OK;
//}
//
//Status DeQueue(SqQueue &Q, QElemType &e){
//	if (Q.front == Q.rear) return ERROR;
//	e = Q.base[Q.front];
//	Q.front = (Q.front + 1) % MAXQSIZE;
//	return OK;
//}
//
//int QueueLength(SqQueue Q){
//	return (MAXQSIZE + Q.rear - Q.front) % MAXQSIZE;
//}
//
//Status GetHead(SqQueue Q, QElemType &e){
//	if (Q.front == Q.rear) return ERROR;
//	e = Q.base[Q.front];
//	return OK;
//}
//
//Status QueueEmpty(SqQueue &Q){
//	if (Q.front == Q.rear) return TRUE;
//	else return FALSE;
//}
//
//Status QueueTraverse(SqQueue Q, Status(*Visit)(QElemType e)){
//	if (Q.front == Q.rear) return ERROR;
//	int i, length;
//	length = QueueLength(Q);
//	for (i = 0; i < length; i++)
//	{
//		visit(Q.base[(Q.front + i) % MAXQSIZE]);
//	}
//	return OK;
//}
//
//
//
