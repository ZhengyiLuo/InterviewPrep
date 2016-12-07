/**
 * @Time: Nov 6, 2016
 * @Author: zen partitioning used in quicksort
 */

public class lintCode1 {
    public int partitionArray(int[] nums, int k) {
        if (nums.length == 0) {
            return 0;
        }
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            if (nums[left] >= k) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                right--;
            } else {
                left++;
            }

        }
        return left;

    }

//    public void sortNutsAndBolts(String[] nuts, String[] bolts, NBComparator compare) {
//        if (nuts.length <= 1) {
//            return;
//        }
//        String[] resultNuts = new String[nuts.length];
//
//        for (int i = 0; i < bolts.length; i++) {
//            int pos = partition(bolts, nuts[i], compare);
//            resultNuts[pos] = nuts[i];
//        }
//
//        nuts = resultNuts;
//
//    }
//
//    public int partition(String[] bolts, String nut, NBComparator compare) {
//
//    }
}
