import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;

/**
 * @Time: Oct 15, 2016
 * @Author: ZhengyiLuo
 * 
 * 
 * 
 * Airbnb new graduate solu
 */

public class AirbnbSolu1 {
    static String[] paginate(int num, String[] results) {
        HashSet<String> seenId = new HashSet<>();
        String[] output = new String[results.length];
        boolean[] seen = new boolean[results.length];
        int iteration = (results.length - results.length % num) / num + 1;
        Arrays.fill(seen, false);

        Arrays.sort(results, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                double score1 = Double.parseDouble(o1.split(",")[2]);
                double score2 =  Double.parseDouble(o1.split(",")[2]);
                return Double.compare(score1, score2);
            }
        });
        int times = 0;
        while (times < iteration) {
            int i = 0;
            int counter = 0;
            while (i < 6 && counter < results.length) {
                if (!seen[counter] && !seenId.contains(results[counter].split(",")[0])) {
                    output[i + times * num] = results[counter];
                    seenId.add(results[counter].split(",")[0]);
                    seen[counter] = true;
                    i++;
                    counter++;
                }
                counter++;
            }
            counter = 0;

            while (i < 6) {
                if (!seen[counter] && i + times * num < results.length) {
                    output[i + times * num] = results[counter];
                    seen[counter] = true;
                    i++;

                }
                counter++;
                if (counter >= results.length) {
                    break;
                }
            }
            times++;
        }

        return output;
    }

}
