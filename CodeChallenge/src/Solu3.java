/**
 * @Time: Oct 2, 2016
 * @Author: ZhengyiLuo
 */

public class Solu3 {
    static long countMoves(int[] numbers) {
        boolean over = true;
        long result = 0;
        int difference = 0;
        int cursorBiggest = 0;

        int biggest = Integer.MIN_VALUE;
        int secondBiggest = Integer.MIN_VALUE;
        while (over) {
            boolean canContinue = true;
            int prev;
            int cursorSecondBiggest = 0;
            prev = numbers[0];
            biggest = numbers[0];
            secondBiggest = numbers[1];
            for (int i = 1; i < numbers.length; i++) {
                if (i != cursorBiggest) {
                    numbers[i] += difference;
                }

                if (numbers[i] >= biggest) {
                    secondBiggest = biggest;
                    biggest = numbers[i];
                    cursorSecondBiggest = cursorBiggest;
                    cursorBiggest = i;
                } else if (numbers[i] > secondBiggest && numbers[i] != biggest) {
                    secondBiggest = numbers[i];
                    cursorSecondBiggest = i;
                }

                if (prev == numbers[i] && canContinue) {
                    canContinue = true;
                } else {
                    canContinue = false;
                }

            }

            if (canContinue) {
                return result;
            }

            difference = biggest - secondBiggest;
            if (difference == 0) {
                difference = 1;
            }
            System.out.println(result);
            result += difference;

        }

        return result;

    }
}
