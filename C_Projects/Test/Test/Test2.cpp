#include<iostream>
using namespace std;
void sort(int array[], int n);
int main()
{
	int array[] = { 175, 168, 158, 157, 159, 157, 169, 171, 172, 179, 180, 189, 192, 184, 183, 172, 170, 169, 152, 150 };//初始化班级同学的身高
	int temp[20];//temp数组用来保存排序后相邻五个同学的身高差
	for (int i = 0; i<20; i++)//初始化temp数组
	{
		temp[i] = 100;
	}
	sort(array, 20);//将身高的数组按从小到大排序
	cout << "将同学身高从小到大输出：" << endl;
	for (int i = 0; i<20; i++)//输出从小到大排序后的身高数组
	{
		cout << array[i] << " ";
	}
	for (int i = 0; i<16; i++)//保存相邻五个同学的身高差
	{
		temp[i] = array[i + 4] - array[i];
	}
	cout << "所有身高差如下：" << endl;
	for (int i = 0; i<16; i++)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
	int min = temp[0];
	for (int i = 1; i<20; i++)	//寻找temp数组中身高差最小的数值，将其保存在min中
	{
		if (temp[i] <= min)
			min = temp[i];
	}
	cout << "最小的身高差为" << min << endl;     //输出最小的身高差数值
	int key = 0;
	for (int i = 0; i<20; i++)  /*因为temp数组中身高差等于最小的数值的元素不止一个，
								这个for循环是为了找到五人组中身高差最小且平均身高最高的在array数组中相邻五个同学第一个同学的下标key*/
	{
		if (temp[i] == min)
			key = i;
	}
	cout << "The result is:" << endl;
	for (int i = key; i<key + 5; i++) //输出题目要求的五个同学的身高
	{
		cout << array[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

void sort(int array[], int n)  //冒泡排序法
{
	int i, j, temp;
	for (j = 0; j<n - 1; j++)
		for (i = 0; i<n - 1 - j; i++)
		{
			if (array[i]>array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
}
