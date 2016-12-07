import java.util.HashMap;

/**
 * @Time: Oct 20, 2016
 * @Author: ZhengyiLuo
 */

public class ValidWordAbbr {
    HashMap<String, String> set = new HashMap();

    public ValidWordAbbr(String[] dictionary) {
        String abbrv;
        for (String str : dictionary) {
            if (str.length() < 2) {
                abbrv = str;
            } else {
                abbrv = str.charAt(0) + String.valueOf(str.length()) + str.charAt(str.length() - 1);
            }

            if (set.containsKey(abbrv)) {
                if (!set.get(abbrv).equals(str)) {
                    set.put(abbrv, "");
                }

            } else {
                set.put(abbrv, str);
            }

        }

    }

    public boolean isUnique(String word) {
        String abbrv;
        if (word.length() < 2) {
            abbrv = word;
        } else {
            abbrv = word.charAt(0) + String.valueOf(word.length()) + word.charAt(word.length() - 1);
        }
        String bool = set.get(abbrv);
        if (bool != null) {
            if (bool.equals(word)) {
                return true;
            }
            return false;
        } else {
            return true;
        }
    }
}

// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa = new ValidWordAbbr(dictionary);
// vwa.isUnique("Word");
// vwa.isUnique("anotherWord");