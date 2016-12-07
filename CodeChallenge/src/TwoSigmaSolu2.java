import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

/**
 * @Time: Oct 9, 2016
 * @Author: ZhengyiLuo
 */

public class TwoSigmaSolu2 {
    static int friendCircles(String[] friends) {
        // Run BFS
        int result = 0;
        boolean[] checked = new boolean[friends.length];
        Arrays.fill(checked, false);
        Queue<Integer> queue = new ArrayDeque<>();
       

        for (int j = 0; j < checked.length; j++) {
            if (!checked[j]) {
                queue.add(j);
                while (!queue.isEmpty()) {
                    int checking = queue.peek();
                    checked[checking] = true;
                    char[] array = friends[checking].toCharArray();
                    for (int i = 0; i < array.length; i++) {
                        if (array[i] == 'Y' && i != checking && !checked[i]) {
                            queue.add(i);
                            checked[i] = true;
                        }
                    }
                    queue.poll();

                }
                result++;
            }

        }

        return result;
    }

}
