#include<iostream>
using namespace std;
#define N 5 //��������ĳ���
//int main()
//{
//	int a[N] = { 1, 2, 3, 4, 5 };//��ʼ������
//	int low[N] = { 0 }, high[N] = { 0 }, num_1[N] = { 0 }, num_2[N] = { 0 };/*low[k]��������a[0]��a[k-1]�б�a[k]С�ĸ�����high[k]��������a[k+1]��a[N-1]�б�a[k]��ĸ�����num_1[k]=low[k]*high[k],������j=k,ʱ�������Ԫ��ĸ�����ͬʱ����Ϊ��a[0]��a[k-1]�б�a[k]С�����ĸ�����low[k]����ô������a[k]������ĸ���Ϊk-low[k],ͬ����a[k+1]��a[N-1]�б�a[k]������ĸ�����high[k],��ô������a[k]С�����ĸ���ΪN-1-(k+1)+1-high[k]=N-k-1-high[k]��Num_2[k]=��k-low[k])*(N-k-1-high[k])��*/
//	int count = 0, count_1 = 0, count_2 = 0;/*count�����������е���Ԫ��ĸ�����count_1�������� ����Ԫ�������count_2�������� ����Ԫ�������*/
//	for (int k = 1; k<N - 1; k++)	//������������
//	{
//		for (int i = 0; i<k; i++)/*��a[0]��a[k-1]��ͳ�Ʊ�a[k]С�ĸ�������low[k]��*/
//		{
//			if (a[i]<a[k]);
//			low[k]++;
//		}
//		for (int i = k + 1; i<N; i++) /*��a[k+1]��a[N-1]��ͳ�Ʊ�a[k]��ĸ�������high[k]��*/
//		{
//			if (a[i]>a[k]);
//			high[k]++;
//		}
//		num_1[k] = low[k] * high[k]; //��������ʱ�Ѿ�����
//		num_2[k] = (k - low[k])*(N - k - 1 - high[k]);
//	}
//	for (int i = 0; i<N; i++)	//��num_1��num_2����������
//	{
//		count_1 += num_1[i];
//		count_2 += num_2[i];
//	}
//	count = count_1 + count_2;
//	cout << count << endl;
//	system("pause");
//	return 0;
//}
