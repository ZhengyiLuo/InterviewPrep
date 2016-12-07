import java.util.*;

class EvaluateDivision {
	public static void main(String[] args) {
		System.out.println("ggg");
	}
}

class Solution {
	HashMap<String,Double> edge = new HashMap<>();
	HashMap<String,node> graph = new HashMap<>();

	public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
		if (equations.length == 0 || values.length == 0 || queries.length == 0) {
			return null;
		}
		
		String temp;
		double[] result = new double[queries.length];
		
		for (int i = 0; i < equations.length; i++) {
			String a = 	equations[i][0] ;
			String b = 	equations[i][1] ;
			temp = a+b;
			edge.put(temp, values[i]);
			temp = b+a;
			edge.put(temp, 1/values[i]);
			
			if (graph.containsKey(a)) {
				graph.get(a).addNeighbor(b);
			} else {
				node n = new node();
				n.addNeighbor(b);
				graph.put(a, n);
			}
			
			
			if (graph.containsKey(b)) {
				graph.get(b).addNeighbor(a);
			} else {
				node n = new node();
				n.addNeighbor(a);
				graph.put(b, n);
			}
			
			int counter = 0;
			for (String[] q :queries) {
				result[counter] = findQueuery(q);
				++counter;
			}
			
		}
		 		

		return result;
	}
	
	double	findQueuery(String[] q){
			String a = q[0];
			String b = q[1];
			double result = 0;
			HashSet<String> seen = new HashSet<>();
			
			Stack<String> dfs = new Stack<>();
			boolean loop = true;
			dfs.add(a);
			while (!dfs.isEmpty() && loop) {
				ArrayList<String> list =  graph.get(dfs.peek()).getNeighbor();
				int count = 0;
				for (String l : list) {
					if (l.equals(b)) {
						loop = false;
					}
					if (!seen.contains(l)) {
						dfs.add(l);
						seen.add(l);
						break;	
					}
					count++;
				}
				 if (count == list.size()) {
					dfs.pop();
				}	
			}
			while (dfs.size() > 1) {
				String first   =  dfs.pop();
				String second  =  dfs.peek();
				String lookup = first+ second;
				 result += edge.get(lookup);
			}
	
				return result;
		}	
		
	
	
	class node{
		ArrayList<String> neighbor;
		public node(){
			neighbor = new ArrayList<String>();		
		}
		
		void addNeighbor(String n){
			neighbor.add(n);
		}
		 
		ArrayList<String> getNeighbor(){
			return neighbor;
		}
		
		
		
	}
}

