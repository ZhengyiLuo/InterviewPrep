import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * @Time: Nov 5, 2016
 * @Author: zen
 */

public class kthElement {
    public int find(int[] array, int k) {
        // Find the smallest element in a stream of arrays

        PriorityQueue<Integer> pq = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });

        for (int i = 0; i < array.length; i++) {
            int element = array[i];
            if (pq.size() < k) {
                pq.offer(element);
            } else if (pq.peek() > element) {
                pq.poll();
                pq.offer(element);
            }
        }

        return pq.peek();
    }

}
