#include <iostream>
#include<math.h>
using namespace std;


//int main(){
//	int a[5][5];
//	int i, j, max,min, k , f = 0;
//	for ( i = 1; i < 6; i++)
//	{
//		for ( j = 1; j < 6; j++)
//		{
//			a[i-1][j-1] = i*j;
//		}
//
//	}
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			cout << a[i][j]<<"   ";
//		}
//		cout << endl;
//
//
//	}
//
//	cout << endl;
//
//	for (i = 0; i < 5; i++)
//	{ 
//		k = 0;
//		j = 0;
//		f = 0;
//		max = a[i][j];
//		for (j = 0; j < 5; j++)
//		{
//			if (a[i][j]>max)
//			{
//				max = a[i][j];
//				k++;
//			}
//			
//		}
//		cout << k << endl;
//		min = a[0][k];
//		for ( j = 0; j < 5; j++)
//		{
//			if (a[j][k]<min)
//			{
//				min = a[j][k];
//				f++;
//			}
//		}
//		cout << f << endl;
//		
//		if (i == f)
//			cout << "we find one" <<a[i][k]<<endl;
//		cout << endl;
//
//	}
//
//
//
//
//
//	
//	system("pause");
//		return 0;
//
//}