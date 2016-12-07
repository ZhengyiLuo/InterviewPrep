import java.util.*;

class Untitled {
	public static void main(String[] args) {
		System.out.print("gg");
	}
}


class Solution {
	public String minWindow(String s, String t) {
		Set<Character> alphbet = new HashSet<Character>();
		HashMap<Character,Integer> counterMap = new HashMap<Character,Integer>();
		int[] result = new int[t.length()];
		int start = 0;
		for (int i = 0; i < t.length(); ++i){
			char c = s.charAt(i);
			alphbet.add(c);			
		}
		
		for (; start < s.length(); ++start){
			char c = s.charAt(start);
			if (alphbet.contains(c)) {
				counterMap.put(c, 1);
				alphbet.remove(c);
				break;
			} else {
				continue;
			}
		}
		
		for (int i = start ; i < s.length(); ++i){
			char c = s.charAt(i);
			if (alphbet.contains(c)) {
				alphbet.remove(c);
				if(counterMap.containsKey(c)){
					counterMap.put(c, counterMap.get(c) +1);
				} else {
					counterMap.put(c, 1);
				}
			} 
			if (alphbet.isEmpty()) {
				result[i] = i - start + 1;
				break;
			}
		}
		
		
		char ch = s.charAt(++start);
		counterMap.put(ch, counterMap.get(ch) - 1);
		if (counterMap.get(ch) != 0) {
			result[]
			break;
		}
		
		
		
		

				
		
		
		return "";
	}
}