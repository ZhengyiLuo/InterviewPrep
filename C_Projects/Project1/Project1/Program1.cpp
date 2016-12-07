#include <iostream>
#include<math.h>
using namespace std;

int main(){
	int x = 0, n = 0;
	
	while (x < 5000){
		int s = 0;
		if (x < 10)
		    s = 0;
		else if (10 < x && x < 100)
			s = 1;
	 	else if (100 < x && x < 1000)
			s = 2;
		else
			s = 3; 

		if (x % 11 == 0){
			switch (s)
			{
			case 0: break;
			case 1: if (x % 10 + (x - x % 10) / 10 == 13)
				n++; break;
					
			case 2: if (x % 10 + (x - x % 100) / 100 + ((x - x % 10 - (x - x % 100)) / 10 == 13))
				n++; break;
					
			case 3: if (x % 10 + (x - x % 1000) / 1000 + (x - (x - x % 1000) - x % 100) / 100 + (x - (x - x % 1000) - (x - (x - x % 1000) - x % 100)) / 10 + x % 10 == 13)
				n++; break;
			default: break;
				 
			}
			cout << s << endl;
		}
		x++;
		
	}
	cout << n << endl;
	system("pause");
	return 0;

}






