#include <iostream>
#include<math.h>
using namespace std;

//int verify(int x);
//
//int main(){
//	int a[101];
//	int i, x, size, half;
//	//double half;
//
//	a[0] = 0;
//	for ( i = 1; i < 101; i++)
//	{
//		a[i] = i;
//	}
//	//cout << "please enter the x" << endl;
//	//cin >> x;
//	for (x = 1; x < 101; x++)
//	{
//
//		size = 100;
//		
//		half = size / 2;
//		size = size / 2;
//		while (size > 0) {
//			if (x < a[half]){
//				half = half - verify(size);
//				
//			}
//			else if (x > a[half]){
//				half = half + verify(size);
//				
//				
//			}
//			else if (x == a[half]) break;
//			size = verify(size);
//			 
//		}
//
//		cout<<x<<"\t" << half << endl;
//	}
//
//	system("pause");
//	return 0;
//
//}
//
//
//int verify(int x){
//	if (x % 2 == 0)
//		return x/2;
//	if (x % 2 != 0)
//		return x / 2 + 1;
//
//}