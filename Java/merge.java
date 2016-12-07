class Untitled {
	public static void main(String[] args) {
		Solution solu = new Solution();
		int[] array1 = {1,2,3,4,0,0,0,0,0,0,0,0};
		int[] array2 = {1,2,3,4};
		solu.merge(array1, 4, array2, 4);
		for (int i = 0; i < array1.length; i++) {
			System.out.print(array1[i]);
		}

		
	}
	

}

class Solution {
	public void merge(int[] nums1, int m, int[] nums2, int n) {
		int cur = m + n -1;
		int n1 = m-1;
		int n2 = n-1;
		while(cur >= 0){
			if(nums1[n1] > nums2[n2]){
				nums1[cur]  = nums1[n1];
				n1--;
			} else{
				nums1[cur]  = nums1[n2];
				n2--;
			}
			
			cur--;
			if(n1 < 0){
				while(cur >= 0){
					nums1[cur]  = nums1[n2];
					 cur--;
					 n2--;
				}
				break;    
			} else if(n2 < 0){
				while(cur >= 0){
					nums1[cur]  = nums1[n1];
					 cur--;
					 n1--;
				}
				break;  
			}
			
			
		}
		
	}
}