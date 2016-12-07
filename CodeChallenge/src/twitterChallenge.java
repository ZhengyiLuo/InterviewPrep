import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

/**
 * @Time: Nov 7, 2016
 * @Author: zen
 */

public class twitterChallenge {
    // int krakenCount(int m, int n) {
    // if (m == 1 || n == 1) {
    // return 1;
    // }
    //
    // return krakenCount(m, n - 1) + krakenCount(m - 1, n - 1) + krakenCount(m
    // - 1, n);
    // }

    int krakenCount(int m, int n) {
        int[][] matrix = new int[m][n];
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            matrix[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i][j - 1];
            }
        }

        return matrix[m - 1][n - 1];
    }

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        String start = sc.nextLine();
        String end = sc.nextLine();
        HashMap<String, StringBuilder> result = new HashMap<>();

        while (sc.hasNext()) {
            String s = sc.nextLine();
            String[] data = s.split(",");
            String[] year = data[0].split("-");
            StringBuilder yeardata = new StringBuilder();
            yeardata.append(year[0]);
            yeardata.append("-");
            yeardata.append(year[1]);
            String time = yeardata.toString();
            if (result.containsKey(time)) {
                result.get(time).append(data[1] + data[2]);
            } else {
                StringBuilder infodata = new StringBuilder();
                infodata.append(data[1] + data[2]);
                result.put(time, infodata);
            }

        }

        for (Iterator iterator = result.keySet().iterator(); iterator.hasNext();) {
            String s = (String) iterator.next();
            System.out.println(s + "," + result.get(s));

        }

    }
}
