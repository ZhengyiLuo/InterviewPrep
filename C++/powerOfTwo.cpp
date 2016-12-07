#include <iostream>

using namespace std;

class Solution {
	public:
		bool isPowerOfTwo(int n) {
			if (n == 0) {
				return  false;
			}
			while (!(n%2)){
				n/=2;
			}
				
				if (n == 1) {
				return true;
			}
			return false;
		}
		
		bool isPowerOfTwo1(int n) {
			return n > 0 && n == (n  &-n);
		}

	};

int main(int argc, char *argv[]) {
	
}