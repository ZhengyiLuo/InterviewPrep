//#include<iostream>
//using namespace std;
//
//#define TRUE 1
//#define FALSE 0
//#define OK 1
//#define ERROR 0
//#define INFESIBLE -1
////#define OVERFLOW -2
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT   10
//
//typedef int Status;
//typedef char SElemType;
//
//struct SqStack
//{
//	SElemType *base;
//	SElemType *top;
//	int stacksize;
//};
//
//
//
// 
//Status InitStack(SqStack &S);
//Status StackLength(SqStack S);
//Status StackEmpty(SqStack S);
//Status Push(SqStack &S, SElemType e);
//Status Pop(SqStack &S, SElemType &);
//Status StackTraverse(SqStack &S, Status(*visit)(SElemType));
//Status GetTop(SqStack &S, SElemType &e);
//Status visit(SElemType c);
// 
////int main(){
////
////
////
////	system("pause");
////	return 0;
////}
//
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
//	cout << c << endl;
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
