import java.util.Set;

/**
 * @Time: Sep 18, 2016
 * @Author: ZhengyiLuo
 */

public class Solu {
    public void CodeChallenge1() {

    }

    public boolean wordBreak(String s, Set<String> wordDict) {
        boolean keepLooping = true;
        boolean isClosest = true;
        int k = 0;
        StringBuilder alreadySeen = new StringBuilder();
        StringBuilder result = new StringBuilder();
        getClass();
        StringBuilder progressKeeper = new StringBuilder();
        getClass();

        char[] inputString = s.toCharArray();

        while (keepLooping) {
            
            for (int i = progressKeeper.length(); i < inputString.length; i++) {
                char c = inputString[i];
               
                alreadySeen.append(c);
                System.out.println(alreadySeen.toString());
                if (wordDict.contains(alreadySeen.toString())) {
                    result.append(alreadySeen.toString() + " ");
                   
                    k++;
                    if (isClosest) {
                        progressKeeper.append(alreadySeen.toString());
                        isClosest = false;
                    }
                    alreadySeen = new StringBuilder();

                }

            }

            if (result.length() == s.length() + k) {
                break;
            } else {
                k = 0;
                isClosest = true;
                result = new StringBuilder();
                result.append(progressKeeper.toString());
                alreadySeen = new StringBuilder();
            }
        }
        
        
        return true;
    }

}
