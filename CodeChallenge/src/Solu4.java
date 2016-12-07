
/**
 * @Time: Oct 17, 2016
 * @Author: ZhengyiLuo
 * 
 * 
 *          121. Best Time to Buy and Sell Stock QuestionEditorial Solution My
 *          Submissions Total Accepted: 137625 Total Submissions: 360809
 *          Difficulty: Easy Contributors: Admin Say you have an array for which
 *          the ith element is the price of a given stock on day i.
 * 
 *          If you were only permitted to complete at most one transaction (ie,
 *          buy one and sell one share of the stock), design an algorithm to
 *          find the maximum profit.
 * 
 *          Example 1: Input: [7, 1, 5, 3, 6, 4] Output: 5
 * 
 *          max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be
 *          larger than buying price) Example 2: Input: [7, 6, 4, 3, 1] Output:
 *          0
 * 
 *          In this case, no transaction is done, i.e. max profit = 0. Show
 *          Company Tags Show Tags Show Similar Problems
 * 
 */

public class Solu4 {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int difference = 0;

        for (int i = 0; i < prices.length; i++) {
            int num = prices[i];
            if (difference < num - min) {
                difference = num - min;
            }

            if (min > num) {
                min = num;
            }

        }

        return difference;
    }
}
