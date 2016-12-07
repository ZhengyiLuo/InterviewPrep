
/**
 * @Time: Oct 12, 2016
 * @Author: ZhengyiLuo Given a non-negative number represented as an array of
 *          digits, plus one to the number.
 * 
 *          The digits are stored such that the most significant digit is at the
 *          head of the list.
 *          
 *             int[] digits = {8,9,9,9,9};
        LeetCodeSolu1 solu1 = new LeetCodeSolu1();
        int[] digit = solu1.plusOne(digits);
        for (int i = 0; i < digit.length; i++) {
            System.out.println(digit[i]);
        }
       
 */

public class LeetCodeSolu1 {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length-1; i >= 0; i--) {
            digits[i] = digits[i] + 1;
            if (digits[i] < 10) {
                break;
            } else {
                digits[i] = 0;
            }

        }
        if (digits[0] == 0) {
            int length = digits.length+1;
            digits = new int[length];
            digits[0] = 1;
            
        }
        
        

        return digits;

    }
}
