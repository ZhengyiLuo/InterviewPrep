#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESIBLE -1
//#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT   10
#define MAXSTRLEN 255
typedef char SString[MAXSTRLEN + 1];

void get_next(SString T, int next[]);
int Index_KMP(SString S, SString T );

//int main(){
//	SString a = "7abaabcacab", b = "2ab";
//	int next[MAXSTRLEN+1], i;
//	get_next(a, next);
//	/*for ( i = 1; i <= 10; i++)
//	{
//		cout << next[i] << endl;
//	}*/
//	cout << Index_KMP(a, b) << endl;
//
//	system("pause");
//}

void get_next(SString T, int next[]){
	int j, i = 1;
	next[1] = 0;
	j = 0;
	while (i<10)
	{
		if (j == 0 || T[i] == T[j]){
			++i;
			++j;
			next[i] = j;
		}
		else j = next[j];
	}
}

int Index_KMP(SString S, SString T){
	int j = 1, i = 1, next[MAXSTRLEN + 1];
	get_next(T, next);
	while (i<=7&&j <= 2){
		if (j == 0|| S[i]==T[j])
		{
			i++;
			j++;
		}
		else j = next[j];
	}
	if (j>2)
	{
		return i - 2;
	}
	else return 0;

}