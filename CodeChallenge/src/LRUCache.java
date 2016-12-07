import java.util.HashMap;
import java.util.LinkedList;

public class LRUCache {
    HashMap<Integer, Integer> map;
    LinkedList<Integer> l;
    int capacity = 0;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        l = new LinkedList<>();
    }

    public int get(int key) {
        if (map.containsKey(key)) {
            l.remove(new Integer(key));
            l.add(key);
            return map.get(key);
        }
        return -1;

    }

    public void set(int key, int value) {
        if (map.containsKey(key)) {
            l.remove(new Integer(key));
            l.add(key);
            map.put(key, value);
            return;
        }
        if (map.size() >= capacity) {
            int first = l.removeFirst();
            map.remove(first);
            map.put(key, value);
            l.add(key);
            return;
        }
        l.add(key);
        map.put(key, value);
    }
}
//
//
///**
// * @Time: Oct 19, 2016
// * @Author: ZhengyiLuo
// */
//
//public class LRUCache {
//    //Hashmap using linear probing. Not working code
//    E[] map;
//    int capacity;
//    int size;
//    int prev = 0;
//
//    public LRUCache(int capacity) {
//        this.capacity = capacity;
//        map = new E[capacity];
//    }
//
//    public int get(int key) {
//        int code = getHashCode(key);
//        E element = map[code];
//        if (element != null) {
//            if (element.key == key) {
//                return element.value;
//            } else {
//                int result = probe(key);
//                if (result > 0) {
//                    return map[result].value;
//                } else {
//                    return result;
//                }
//            }
//        }
//        return -1;
//    }
//
//    public void set(int key, int value) {
//        size++;
//        if (size > capacity) {
//            map[prev] = null;
//            size--;
//        }
//        int position = probe(key);
//        if (position == -1) {
//            map[prev] = new E(key, value);
//        } else {
//            map[position] = new E(key, value);
//            return;
//        }
//
//    }
//
//    public int getHashCode(int key) {
//        return key % capacity;
//    }
//
//    public int probe(int key) {
//        int code = getHashCode(key);
//        boolean found = false;
//        for (int i = 0; i < map.length; i++) {
//            if (map[code] == null) {
//                break;
//            }
//            if (map[code].key == key) {
//                found = true;
//                break;
//            }
//            code++;
//            if (code >= map.length) {
//                code = 0;
//            }
//        }
//
//        if (found) {
//            return code;
//        } else {
//            prev = code;
//            return -1;
//        }
//    }
//
//    class E {
//        int key;
//        int value;
//
//        E(int key, int value) {
//            this.key = key;
//            this.value = value;
//        }
//
//    }
//}