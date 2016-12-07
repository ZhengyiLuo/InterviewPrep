#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Solution {
	public:
		bool validWordAbbreviation(string word, string abbr) {
			int digit;
			int pos = 0;
			regex rgx("\\d+|\\D+");
			sregex_token_iterator iter(abbr.begin(), abbr.end(), rgx, 0);
			sregex_token_iterator end;
			for ( ; iter != end; ++iter){
				string str = *iter;
				
				if (isdigit(str[0])) {
				if (str[0] == '0') {
					return false;
				}
					digit = stoi(str);
					pos+= digit;
					
					
				} else {
					 
					if (word.compare(pos, str.size(), str) != 0) {
						return false;
					}
					pos+=str.size();
					
					
				}
							
			}
	
			if (pos != word.size() ) {
				return false;
			}
			
			return true;
		}
	};


int main(int argc, char *argv[]) {
	Solution solu = Solution();
	 cout<<solu.validWordAbbreviation("a", "01");

}