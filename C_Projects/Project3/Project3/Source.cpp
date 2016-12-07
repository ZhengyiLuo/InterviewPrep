#include <iostream>
#include<math.h>
using namespace std;

struct Student
{
	char index[5] ;
	char name[10]  ;
	char birthday[5]  ;
	int score  ;
	int flag  ;
};


int main(){
	int k = 0;
	while (k < 5){
		Student student[5] = { { "app1", "xiaoming", { '0', '4', '3', '0' }, 99, 1 }, { "app2", "xiaoming", { '0', '4', '3', '0' }, 99, 1 }, { "app3", "xiaoming", { '0', '4', '3', '0' }, 99, 1 }
		, { "app4", "xiaoming", { '0', '4', '3', '0' }, 99, 1 }, { "app5", "xiaoming", { '0', '4', '3', '0' }, 99, 1 } }, temp;
		int i, j, x, num;
		char index[5];
		num = 5;

		for (i = 0; i < num; i++)
		{

			/*student[i].index[0] = '0'+i;
			cout << "printin name " << i << endl;
			cin >> student[i].name;
			cout << "printin birthday " << i <<"  format:0425"<< endl;
			cin >> student[i].birthday;
			cout << "printin score " << i << endl;
			cin >> student[i].score;
			student[i].flag = 1;*/


		}

		cout << "enter the index" << endl;
		cin >> index;
		for (i = 0; i < num; i++)
		{
			if (strcmp(index, student[i].index) == 0){
				cout << student[i].index << "\t";
				cout << student[i].name << "\t";
				cout << student[i].birthday << "\t";
				cout << student[i].score << "\t";
				cout << endl;
				x = i;
				//	student[i].flag = 0;

			}
		}

		cout << x << endl;
		int a = x;
		for (j = 0; j < num - a-1; j++)
		{
			student[x] = student[x + 1];
			x++;
		}


		cout << endl;
		cout << endl;
		cout << endl;

		for (i = 0; i < num -1; i++)
		{

			cout << student[i].index << "\t";
			cout << student[i].name << "\t";
			cout << student[i].birthday << "\t";
			cout << student[i].score << "\t";
			cout << endl;


		}





		k++;
	}


	system("pause");
	return 0;

}