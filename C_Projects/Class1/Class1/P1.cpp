#include <iostream>

using namespace std;
void p116();


int main(){
	int n, a[100],i, x, x_mutiple, sum = 0;
	cout << "please enter n:";
	cin >> n;
	
	for ( i = 0; i <= n; i++)
	{
		cout << "please enter a:";
		cin >> a[i];
	}
	
	cout << "please enter x:";
	cin >> x;
	x_mutiple = 1;

	sum = sum + x_mutiple*a[0];

	for ( i = 1; i <=n; i++)
	{
		x_mutiple = x*x_mutiple;
		sum = sum + x_mutiple*a[i];

	}
	cout << endl;
	cout << sum << endl;

	system("pause");
	return 0;
}


void p116(){
	int x, y, z, temp;
	cout << "Please enter x" << endl;
	cin >> x;
	cout << "Please enter y" << endl;
	cin >> y;
	cout << "Please enter z" << endl;
	cin >> z;

	if (x < y){
		temp = x;
		x = y;
		y = temp;
	}

	if (x < z){
		temp = x;
		x = z;
		z = temp;
	}

	if (y < z){
		temp = y;
		y = z;
		z = temp;
	}

	cout << x << "   " << y << "   " << z;
}