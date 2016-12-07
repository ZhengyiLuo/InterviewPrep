class ArraysP1 {
	public static void main(String[] args) {
		
		System.out.println(isUnique("ihateyousmc"));
			}
			
    public static boolean isUnique (String input){
	int[] check = new int[25];
	char[] inputString = input.toCharArray();
	for (int i = 0; i < input.length(); i++) {
		int inputChar = inputString[i];
		int inputCharNum;
		if (inputChar < 97 || inputChar > 122) {
			throw  new IllegalArgumentException();
		} else {
			 inputCharNum = inputChar - 97;
		}
		
		if (check[inputCharNum] == 0) {
			check[inputCharNum]  = 1;
		} else {
			return false;
		}

	}
	
	
	
	return true;
	
    }
			
}


