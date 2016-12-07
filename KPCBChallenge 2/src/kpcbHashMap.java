
/**
 * @Time: Sep 30, 2016
 * @Author: ZhengyiLuo
 */

/**
 * @author ZhengyiLuo
 *kpcbHashp map implemented using object array. An hashmap that resolve collision through chaining. 
 * @param <K>
 * @param <V>
 */
public class kpcbHashMap<K, V> {
    Object[] table;
    int capacity;
    int size;
    boolean continas;
    item<K, V> prev;

    /**
     * Create a new instance of kpcbHashMap by passing the capacity
     * 
     * @param int
     * 
     */
    public kpcbHashMap(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException();
        }
        this.capacity = capacity;
        table = new Object[capacity];
    }

    /**
     * add a new value or override an existing value in the hashmap of
     * kpcbHashMap. Throws exception if the passed in key is a null.
     * 
     * @param K
     * @param V
     * 
     */
    public boolean set(K key, V value) {
        if (key == null) {
            throw new IllegalArgumentException();
        }

        int code = getHashCode(key);

        if (table[code] == null) {

            if (size >= capacity) {
                return false;
            }
            size++;
            table[code] = new item<>(key, value);
        } else {

            @SuppressWarnings("unchecked")
            item<K, V> i = (item<K, V>) table[code];
            item<K, V> current = findKey(i, key);
            if (continas) {
                continas = false;
                current.setValue(value);
            } else {

                if (size >= capacity) {
                    return false;
                }
                size++;
                current.setNext(new item<>(key, value));
            }
        }

        return true;
    }

    /**
     * Get the value assosciated with the key. Return null if the key is not
     * present in the map. Throw illegalArgument exception if the key is null
     * 
     * @param K
     * 
     */
    public V get(K key) {
        if (key == null) {
            throw new IllegalArgumentException();
        }
        int code = getHashCode(key);

        if (table[code] == null) {
            return null;
        } else {
            @SuppressWarnings("unchecked")
            item<K, V> i = findKey((item<K, V>) table[code], key);
            if (continas) {
                continas = false;
                return i.getValue();
            }
        }
        return null;
    }

    /**
     * Delete the value associated with the key. Throw illegal argument
     * exception if the key is a null.
     * 
     * @param K
     * 
     */
    public boolean delete(K key) {
        if (key == null) {
            throw new IllegalArgumentException();
        }

        int code = getHashCode(key);
        if (table[code] == null) {
            return false;
        } else {
            @SuppressWarnings("unchecked")
            item<K, V> i = findKey((item<K, V>) table[code], key);
            if (continas) {
                continas = false;
                if (prev.equals(i)) {
                    if (i.next == null) {
                        table[code] = null;
                    } else {
                        table[code] = i.getNext();
                    }

                } else {
                    prev.setNext(i.getNext());
                }
                size--;
                return true;
            } else {
                return false;
            }
        }

    }

    /**
     * Return the load factor of the hashmap as a float.
     * 
     */
    public float load() {
        return (float) size / (float) capacity;

    }

    // Helper function for find the current key value pair.
    private item<K, V> findKey(item<K, V> i, K key) {
        if (i.getKey().equals(key)) {
            continas = true;
            prev = i;
            return i;
        }

        while (i != null) {
            if (i.getKey().equals(key)) {
                continas = true;
                return i;
            }
            prev = i;
            i = i.getNext();
        }

        return prev;
    }

    // Generating hashCode for an object.
    public int getHashCode(K key) {
        return key.hashCode() % capacity;
    }

    /**
     * Inner class for creating the linked list for item for creating a hashmap
     * with Chaining.
     *
     * @param <K>
     * @param <V>
     */
    @SuppressWarnings("hiding")
    private class item<K, V> {

        private K key;
        private V value;
        private item<K, V> next;

        /**
         * Create a new item, if key is null, thrwo a illegalArgumentException.
         * 
         * @param <K>
         * @param <V>
         */
        public item(K key, V value) {
            if (key == null) {
                throw new IllegalArgumentException();
            }
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public void setValue(V value) {
            this.value = value;
        }

        public item<K, V> getNext() {
            return next;
        }

        public void setNext(item<K, V> next) {
            this.next = next;
        }

        @SuppressWarnings("unchecked")
        @Override
        public boolean equals(Object obj) {
            item<K, V> object = null;
            if (obj != null && obj instanceof item) {
                object = (item<K, V>) obj;
            } else {
                return false;
            }

            if (object.getKey().equals(key) && object.getValue().equals(value)) {
                return true;
            }

            return super.equals(obj);
        }

    }

}
