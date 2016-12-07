import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * @Time: Oct 15, 2016
 * @Author: ZhengyiLuo
 * 
 *   String line1 = "abcd";
        String line2 = "dcba";
        String line3 = "lls";
        String line4 = "s";
        String line5 = "sssll";
        String[] input = { line1, line2, line3, line4, line5 };
        LeetCodeSolu4 solu4 = new LeetCodeSolu4();
        System.out.println(solu4.palindromePairs(input));

 */

public class LeetCodeSolu4 {
    public List<List<Integer>> palindromePairs(String[] words) {
        ArrayList<List<Integer>> result = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            map.put(words[i], i);
        }

        for (int i = 0; i < words.length; i++) {
            String string = (new StringBuilder(words[i]).reverse().toString());

            for (int j = 0; j < words[i].length(); j++) {
                String substring = string.substring(j, words[i].length() );
                if (isPal(words[i] + substring)) {

                    if (map.containsKey(substring)) {
                        int index = map.get(substring);
                        if (index != i) {
                            ArrayList<Integer> list = new ArrayList<>();
                            list.add(index);
                            list.add(i);
                            result.add(list);
                        } else {
                            if (map.containsKey("")) {
                                ArrayList<Integer> list = new ArrayList<>();
                                list.add(map.get(""));
                                list.add(i);
                                result.add(list);

                                ArrayList<Integer> list2 = new ArrayList<>();
                                list2.add(i);
                                list2.add(map.get(""));
                                result.add(list2);
                            }
                        }
                    }

                } else {
                    break;
                }

            }
        }

        return result;

    }

    public boolean isPal(String input) {
        String first = input.substring(0, input.length() / 2);
        String second = (new StringBuilder(input.substring(input.length() / 2, input.length())).reverse().toString());
        
        if (first.equals(second)) {
            return true;
        }
        return false;
    }

}
