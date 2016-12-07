#include<iostream>
using namespace std;
#define N 5 //定义数组的长度
//int main()
//{
//	int a[N] = { 1, 2, 3, 4, 5 };//初始化数组
//	int low[N] = { 0 }, high[N] = { 0 }, num_1[N] = { 0 }, num_2[N] = { 0 };/*low[k]用来保存a[0]到a[k-1]中比a[k]小的个数；high[k]用来保存a[k+1]到a[N-1]中比a[k]大的个数；num_1[k]=low[k]*high[k],即保存j=k,时，这个三元组的个数。同时，因为在a[0]到a[k-1]中比a[k]小的数的个数是low[k]，那么比其中a[k]大的数的个数为k-low[k],同理，在a[k+1]到a[N-1]中比a[k]大的数的个数是high[k],那么比其中a[k]小的数的个数为N-1-(k+1)+1-high[k]=N-k-1-high[k]。Num_2[k]=（k-low[k])*(N-k-1-high[k])。*/
//	int count = 0, count_1 = 0, count_2 = 0;/*count用来保存所有的三元组的个数，count_1用来保存 的三元组个数，count_2用来保存 的三元组个数。*/
//	for (int k = 1; k<N - 1; k++)	//遍历整个数组
//	{
//		for (int i = 0; i<k; i++)/*在a[0]到a[k-1]中统计比a[k]小的个数存在low[k]中*/
//		{
//			if (a[i]<a[k]);
//			low[k]++;
//		}
//		for (int i = k + 1; i<N; i++) /*在a[k+1]到a[N-1]中统计比a[k]大的个数存在high[k]中*/
//		{
//			if (a[i]>a[k]);
//			high[k]++;
//		}
//		num_1[k] = low[k] * high[k]; //定义数组时已经解释
//		num_2[k] = (k - low[k])*(N - k - 1 - high[k]);
//	}
//	for (int i = 0; i<N; i++)	//对num_1和num_2数组进行求和
//	{
//		count_1 += num_1[i];
//		count_2 += num_2[i];
//	}
//	count = count_1 + count_2;
//	cout << count << endl;
//	system("pause");
//	return 0;
//}
