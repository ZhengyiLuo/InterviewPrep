import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;

/**
 * @Time: Oct 9, 2016
 * @Author: ZhengyiLuo
 * 
 *  String line1 = "a";
      String line2 = "b";
      String line3 = "ba";
      String line4 = "bca";
      String line5 = "bda";
      String line6 = "bdca";
      String line7 = "bdcab";
      String[] input = { line1, line2, line3, line4, line5 , line6, line7};
      System.out.println(TwoSigmaSolu1.longestChain(input));
 */

public class TwoSigmaSolu1 {
    static int longestChain(String[] words) {
        int result = 0;
        int prevLength = 0;
        int[] resultArray = new int[words.length];
        HashMap<String, Integer> prevLengthSet = new HashMap<>();
        HashMap<String, Integer> currentLengthSet = new HashMap<>();

        Arrays.sort(words, new Comparator<String>() {

            @Override
            public int compare(String s1, String s2) {
                int result = s1.length() - s2.length();
                return result;
            }
        });

        for (int i = 0; i < words.length; i++) {
            String current = words[i];
            if (i == 0) {
                prevLength = 1;
                currentLengthSet.put(current, i);
                resultArray[i] = 1;
                continue;
            }

            if (current.length() > prevLength) {
                prevLength = current.length();
                prevLengthSet = new HashMap<>(currentLengthSet);
                currentLengthSet = new HashMap<>();
                currentLengthSet.put(current, i);
            } else {
                currentLengthSet.put(current, i);
            }

            int max = Integer.MIN_VALUE;

            for (int j = 0; j < current.length(); j++) {

                String substracted = current.substring(0, j) + current.substring(j + 1);

                if (prevLengthSet.containsKey(substracted)) {
                    max = max(max, resultArray[prevLengthSet.get(substracted)] + 1);
                }
            }

            if (max < 0) {
                resultArray[i] = 1;
            } else {
                resultArray[i] = max;
            }

            result = max(result, max);

        }

        for (int i = 0; i < resultArray.length; i++) {
            System.out.println(resultArray[i]);
        }

        return result;
    }

    static int max(int n1, int n2) {
        return n1 < n2 ? n2 : n1;
    }

}
