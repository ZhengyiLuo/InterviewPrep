//
class Solution {
	public:
		vector<string> generatePossibleNextMoves(string s) {
			vector<string> result = vector<string>();
			if(s.empty() || s.size() == 0){
				return result;
			}
			
			for(int i = 0; i < s.size()-1; i++){
				
				if(s[i+1] == '+'){
					if(s[i] == '+'){
						
						string news;
						news = s;
						news[i] = '-';
						news[i+1] = '-';
						result.push_back(news);
					}
					
				} else{
					++i;
				}
			}
		  
		  
			return result;
			
		}
	};