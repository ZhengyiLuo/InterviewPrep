import java.util.Arrays;

/**
 * @Time: Nov 6, 2016
 * @Author: zen
 */

public class LeetCodeSolu9 {
    public int lengthOfLIS(int[] nums) {            
        int[] dp = new int[nums.length];
        int len = 0;

        for(int x : nums) {
            int i = Arrays.binarySearch(dp, 0, len, x);
            if(i < 0) i = -(i + 1);
            dp[i] = x;
            if(i == len) len++;
        }

        return len;
    }
//    public int lengthOfLIS(int[] nums) {
//        if (nums.length <= 1) {
//            return nums.length;
//        }
//        int maxResult = 1;
//        int[] longest = new int[nums.length];
//        longest[nums.length - 1] = 1;
//        for (int i = nums.length - 1; i >= 0; --i) {
//            int curlongest = findCloestBig(nums, longest, i);
//
//            if (curlongest == i) {
//                longest[i] = 1;
//
//            } else {
//                longest[i] += longest[curlongest] + 1;
//            }
//            if (longest[i] > maxResult) {
//                maxResult = longest[i];
//
//            }
//        }
//
//        return maxResult;
//
//    }
//
//    public int findCloestBig(int[] nums, int[] longest, int pos) {
//        int result = pos;
//        int max = 0;
//        for (int i = pos; i < nums.length; ++i) {
//            int element = nums[i];
//            if (element > nums[pos]) {
//                if (max < longest[i]) {
//                    result = i;
//                    max = longest[i];
//                }
//
//            }
//        }
//        return result;
//    }

}
