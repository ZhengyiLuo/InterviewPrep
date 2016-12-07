//#include<iostream>
//using namespace std;
//#define SWAP(x,y)  {DataType t=x;x=y;y=t;}  
//
//typedef int DataType;
//
//
//int quickSelect(DataType* A, int begin, int end, int K);
//
////int main(){
////	int a[] = { 1,2,4, 5, 6, 7, 8, 9, 10, 43, 73 };
////	cout<<quickSelect(a, 0, 11, 3)<<endl;
////	system("pause");
////	return 0;
////}
//
//int quickSelect(DataType* A, int begin, int end, int K)
//{
//	DataType pivot;
//	int i, j;
//
//	if (end - begin + 1 < K)  // error  
//	{
//		cout<<"error!\n";
//		return 0;
//	}
//
//	pivot = A[begin];
//	i = begin;
//	j = end + 1;
//
//	 
//	for (;;)
//	{
//		while (A[++i] < pivot);
//		while (A[--j] > pivot);
//		if (i > j) break;
//		SWAP(A[i], A[j]);
//	}
//	SWAP(A[begin], A[j]);
//
//	if (j - begin == K - 1)   
//		return A[j];
//	else if (j - begin >= K) 
//		return quickSelect(A, begin, j - 1, K);
//	else
//		return quickSelect(A, j + 1, end, K - (j - begin + 1));
//}