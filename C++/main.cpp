#include <iostream>
#include <list>
using namespace std;

class MovingAverage {
	public:
		/** Initialize your data structure here. */
		std::list<double> *list;
		double prev;
		int size;
		int counter;
		double sum;
		MovingAverage(int size) {
			this->size = size;
			list = new std::list<double>();
			this->counter = 0;
			this->sum = 0;
		}
		
		double next(int val) {
			
			if (counter == size) {
				sum -= list->back();
				sum += val;
				list->pop_back();
				list->push_front(val);
				

			} else {
				sum = 0;
				counter++;
				list->push_front(val);
				for (double i: *list) {
					sum += i;
				}
			}
				return sum/counter;
				
		}

};


int main(int argc, char *argv[]) {
    
	MovingAverage *mv = new MovingAverage(1);
	mv->next(1);

	
	
	
}



