import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * @Time: Oct 15, 2016
 * @Author: ZhengyiLuo Given an array of integers, return indices of the two
 *          numbers such that they add up to a specific target.
 *          
 *          
 *          int[] input = { 1, -1, -1, 0 };
        LeetCodeSolu3 solu3 = new LeetCodeSolu3();
        List<List<Integer>> list = solu3.threeSum(input);
        for (Iterator iterator = list.iterator(); iterator.hasNext();) {
            List<Integer> list2 = (List<Integer>) iterator.next();
            for (Iterator iterator2 = list2.iterator(); iterator2.hasNext();) {
                Integer integer = (Integer) iterator2.next();
                System.out.print(integer + " ");
            }
        }
 */

public class LeetCodeSolu3 {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        HashMap<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int wanted = target - nums[i];
            if (seen.containsKey(wanted)) {
                result[0] = seen.get(wanted);
                result[1] = i;
                return result;
            }
            seen.put(nums[i], i);
        }
        return result;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int up = nums.length - 1;
            int down = i + 1;
            int target = 0 - nums[i];
            while (up != down) {
                // Use the fact that this array is sorted to remove the
                // duplicates
                if (up != nums.length - 1 && nums[up] == nums[up + 1]) {
                    up--;
                    continue;
                }
                if (down != i + 1 && nums[down] == nums[down - 1]) {
                    down++;
                    continue;
                }

                if (target == nums[up] + nums[down]) {
                    ArrayList<Integer> list = new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[down]);
                    list.add(nums[up]);
                    result.add(list);
                    up--;
                    down++;
                    if (up == down - 1) {
                        break;
                    }
                } else if (target > nums[up] + nums[down]) {
                    down++;
                } else {
                    up--;
                }
            }
        }
        return result;

    }

    public List<List<Integer>> fourSum(int[] nums, int target) {

        return null;

    }
}
