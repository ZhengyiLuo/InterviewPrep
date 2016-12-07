//#include<iostream>
//using namespace std;
//
//#define TRUE 1
//#define FALSE 0
//#define OK 1
//#define ERROR 0
//#define MAXQSIZE 100
//
//typedef char QElemType;
//typedef int Status;
//
//struct SqQueue{
//	QElemType *base;
//	int front;
//	int rear;
//};
//
//Status InitQueue(SqQueue &Q);
//Status QueueEmpty(SqQueue &Q);
//Status EnQueue(SqQueue &Q, QElemType e);
//Status DeQueue(SqQueue &Q, QElemType &e);
//int QueueLength(SqQueue Q);
//Status GetHead(SqQueue Q, QElemType &e);
//Status QueueTraverse(SqQueue Q, Status (*Visit)(QElemType e));
//Status visit(QElemType c);
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
//	if (Q.front = Q.rear) return ERROR;
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
//	if (Q.front = Q.rear) return ERROR;
//	e = Q.base[Q.front];
//	return OK;
//}
//
//Status QueueEmpty(SqQueue &Q){
//	if (Q.front = Q.rear) return TRUE;
//	else return FALSE;
//}
//
//Status QueueTraverse(SqQueue Q, Status(*Visit)(QElemType e)){
//	if (Q.front == Q.rear) return ERROR;
//	int i, length;
//	length = QueueLength(Q);
//	for ( i = 0; i < length; i++)
//	{
//		visit(Q.base[(Q.front + i) % MAXQSIZE]);
//	}
//	return OK;
//}
//
//Status visit(QElemType c)
//{
//	cout << c << endl;
//	return OK;
//}
//
//
//
