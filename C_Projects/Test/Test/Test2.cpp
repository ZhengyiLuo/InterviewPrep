#include<iostream>
using namespace std;
void sort(int array[], int n);
int main()
{
	int array[] = { 175, 168, 158, 157, 159, 157, 169, 171, 172, 179, 180, 189, 192, 184, 183, 172, 170, 169, 152, 150 };//��ʼ���༶ͬѧ�����
	int temp[20];//temp������������������������ͬѧ����߲�
	for (int i = 0; i<20; i++)//��ʼ��temp����
	{
		temp[i] = 100;
	}
	sort(array, 20);//����ߵ����鰴��С��������
	cout << "��ͬѧ��ߴ�С���������" << endl;
	for (int i = 0; i<20; i++)//�����С�����������������
	{
		cout << array[i] << " ";
	}
	for (int i = 0; i<16; i++)//�����������ͬѧ����߲�
	{
		temp[i] = array[i + 4] - array[i];
	}
	cout << "������߲����£�" << endl;
	for (int i = 0; i<16; i++)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
	int min = temp[0];
	for (int i = 1; i<20; i++)	//Ѱ��temp��������߲���С����ֵ�����䱣����min��
	{
		if (temp[i] <= min)
			min = temp[i];
	}
	cout << "��С����߲�Ϊ" << min << endl;     //�����С����߲���ֵ
	int key = 0;
	for (int i = 0; i<20; i++)  /*��Ϊtemp��������߲������С����ֵ��Ԫ�ز�ֹһ����
								���forѭ����Ϊ���ҵ�����������߲���С��ƽ�������ߵ���array�������������ͬѧ��һ��ͬѧ���±�key*/
	{
		if (temp[i] == min)
			key = i;
	}
	cout << "The result is:" << endl;
	for (int i = key; i<key + 5; i++) //�����ĿҪ������ͬѧ�����
	{
		cout << array[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

void sort(int array[], int n)  //ð������
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
