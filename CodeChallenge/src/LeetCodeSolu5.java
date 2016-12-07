import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

/**
 * @Time: Oct 19, 2016
 * @Author: ZhengyiLuo
 */

public class LeetCodeSolu5 {
    public RandomListNode copyRandomList1(RandomListNode head) {
        HashMap<RandomListNode, RandomListNode> map = new HashMap<>();
        if (head == null) {
            return null;
        }

        RandomListNode newhead = new RandomListNode(head.label);
        map.put(head, newhead);

        while (head != null) {
            RandomListNode newNode = map.get(head);
            if (!map.containsKey(head.next)) {
                if (head.next != null) {
                    newNode.next = new RandomListNode(head.next.label);
                    map.put(head.next, newNode.next);
                } else {
                    newNode.next = null;
                }
            } else {
                newNode.next = map.get(head.next);
            }

            if (!map.containsKey(head.random)) {
                if (head.random != null) {
                    newNode.random = new RandomListNode(head.random.label);
                    map.put(head.random, newNode.random);
                } else {
                    newNode.random = null;
                }

            } else {
                newNode.random = map.get(head.random);
            }
            head = head.next;
        }
        return newhead;

    }

    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) {
            return null;
        }
        RandomListNode newhead = head;
        while (head != null) {
            RandomListNode newNode = new RandomListNode(head.label);
            newNode.next = head.next;
            head.next = newNode;
            head = newNode.next;
        }

        head = newhead;
        newhead = newhead.next;
        while (head.next.next != null) {
            System.out.println(head.label);
            if (head.random != null) {
                head.next.random = head.random.next;
            } else {
                head.next.random = null;
            }

            RandomListNode temp2 = head.next.next;
            head.next.next = head.next.next.next;
            head = temp2;

        }
        if (head.random != null) {
            head.next.random = head.random.next;
        } else {
            head.next.random = null;
        }

        return newhead;

    }

    class RandomListNode {
        int label;
        RandomListNode next, random;

        RandomListNode(int x) {
            this.label = x;
        }
    };

    public void moveZeroes(int[] nums) {
        int accu = 0;
        for (int i = 0; i < nums.length; i++) {
            int nudge = 0;
            while (i < nums.length && nums[i] == 0) {
                nudge++;
                i++;
            }

            if (nudge != 0) {
                while (i < nums.length && nums[i] != 0) {
                    nums[i - nudge - accu] = nums[i];
                    nums[i] = 0;
                    i++;
                }
                accu += nudge;
                i--;

            }

        }

    }

    public int uniquePaths(int m, int n) {

        double b = Math.min(m, n) - 1;
        double sum = Math.max(m, n) - 1 + b;

        double result = 1;
        for (; b > 0; b--, sum--) {
            result *= sum / b;

        }
        result += 0.001;
        return (int) result;
    }

    public int numIslands(char[][] grid) {
        int size = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                char num = grid[i][j];
                if (num == '1') {
                    checkBound(grid, i, j);
                    size++;
                }

            }

        }
        return size;
    }

    void checkBound(char[][] grid, int i, int j) {
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1') {
            checkBound(grid, i - 1, j);
        }

        if (j - 1 >= 0 && grid[i][j - 1] == '1') {
            checkBound(grid, i, j - 1);
        }

        if (i + 1 < grid.length && grid[i + 1][j] == '1') {
            checkBound(grid, i + 1, j);
        }

        if (j + 1 < grid[i].length && grid[i][j + 1] == '1') {
            checkBound(grid, i, j + 1);
        }

    }

    public class Interval {
        int start;
        int end;

        Interval() {
            start = 0;
            end = 0;
        }

        Interval(int s, int e) {
            start = s;
            end = e;
        }
    }

    public List<Interval> merge(List<Interval> intervals) {
        Collections.sort(intervals, new comparator());
        List<Interval> result = new LinkedList<>();
        if (intervals.isEmpty()) {
            return result;
        }
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;

        for (Interval inter : intervals) {
            if (inter.start <= end) {
                if (inter.end > end) {
                    end = inter.end;
                }

            } else {
                result.add(new Interval(start, end));
                start = inter.start;
                end = inter.end;
            }

        }
        result.add(new Interval(start, end));
        return result;
    }

    public class comparator implements Comparator<Interval> {

        @Override
        public int compare(Interval o1, Interval o2) {
            // TODO Auto-generated method stub
            return o1.start - o2.start;
        }

    }

    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> result = new ArrayList();

        if (nums.length == 0) {
            if (lower == upper) {
                result.add(String.valueOf(lower));
                return result;
            }
            result.add(String.valueOf(lower) + "->" + String.valueOf(upper));
            return result;
        }

        if (nums.length == 1) {
            if (lower == upper) {
                if (nums[0] == lower) {
                    return result;
                }
                result.add(String.valueOf(lower));
                return result;
            }
            if (nums[0] < lower) {
                result.add(String.valueOf(lower) + "->" + String.valueOf(upper));
                return result;
            } else if (nums[0] > upper) {

                result.add(String.valueOf(lower) + "->" + String.valueOf(upper));
                return result;
            } else if (nums[0] == lower) {
                if (lower + 1 == upper) {
                    result.add(String.valueOf(upper));
                    return result;

                }

                result.add(String.valueOf(lower + 1) + "->" + String.valueOf(upper));
                return result;
            } else if (nums[0] == upper) {
                if (lower + 1 == upper) {
                    result.add(String.valueOf(lower));
                    return result;

                }
                result.add(String.valueOf(lower) + "->" + String.valueOf(upper - 1));
                return result;
            } else {
                if (lower == nums[0] - 1) {
                    result.add(String.valueOf(lower));
                } else {
                    result.add(String.valueOf(lower) + "->" + String.valueOf(nums[0] - 1));
                }
                if (nums[0] + 1 == upper) {
                    result.add(String.valueOf(upper));
                } else {
                    result.add(String.valueOf(nums[0] + 1) + "->" + String.valueOf(upper));
                }

                return result;
            }
        }

        int prev = lower;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > prev && nums[i] < upper) {
                if (prev == nums[i] - 1) {
                    result.add(String.valueOf(prev));
                    prev = nums[i] + 1;
                } else {

                    result.add(String.valueOf(prev) + "->" + String.valueOf(nums[i] - 1));
                    prev = nums[i] + 1;

                }

            } else if (nums[i] == prev) {
                prev++;
            } else if (nums[i] > upper) {
                result.add(String.valueOf(prev) + "->" + String.valueOf(upper));
                return result;
            } else if (nums[i] == upper) {
                result.add(String.valueOf(prev) + "->" + String.valueOf(nums[i] - 1));
                return result;
            }

        }
        if (nums[nums.length - 1] < upper) {
            if (nums[nums.length - 1] +1 == upper) {
                result.add(String.valueOf(upper));
            }
            result.add(String.valueOf(prev) + "->" + String.valueOf(upper));
        }

        return result;

    }
    
    
    
}
