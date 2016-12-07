import java.util.Arrays;

/**
 * @Time: Oct 2, 2016
 * @Author: ZhengyiLuo
 */

public class Solu2 {
    static int reductionCost(int[] num) {
        boolean[] checked = new boolean[num.length];
        Arrays.fill(checked, Boolean.TRUE);
        int size = num.length;
        int sum = 0;

        while (size > 1) {
            int smallest = Integer.MAX_VALUE;
            int secondSmallest = Integer.MAX_VALUE;
            int curzorSmallset = 0;
            int curzorSecondSmallset = 0;
            for (int i = 0; i < num.length; i++) {
                if (checked[i]) {
                    if (num[i] < smallest) {
                        smallest = num[i];
                        curzorSmallset = i;
                    }

                }

            }
            checked[curzorSmallset] = false;
            
            for (int i = 0; i < num.length; i++) {
                if (checked[i]) {
                    if (num[i] < secondSmallest) {
                        secondSmallest = num[i];
                        curzorSecondSmallset = i;
                    }

                }

            }
            
            num[curzorSecondSmallset] = secondSmallest + smallest;
            sum += secondSmallest + smallest;
            
            size--;
           
         
        }

        return sum;

    }
}
