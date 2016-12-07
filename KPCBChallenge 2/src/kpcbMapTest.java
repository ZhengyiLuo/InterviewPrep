import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Before;
import org.junit.Test;

/**
 * @Time: Sep 30, 2016
 * @Author: ZhengyiLuo
 */

public class kpcbMapTest {

    kpcbHashMap<String, String> table;
    static final String KEY_1 = "1";
    static final String KEY_2 = "2";
    static final String KEY_3 = "3";
    static final String KEY_4 = "4";
    static final String KEY_5 = "5";
    static final String SAMEHASH1 = "AaAaAa";
    static final String SAMEHASH2 = "AaAaBB";
    static final String SAMEHASH3 = "AaBBAa";
    static final String SAMEHASH4 = "AaBBBB";
    static final String SAMEHASH5 = "BBBBBB";

    static final String VALUE_1 = "I";
    static final String VALUE_2 = "LIKE";
    static final String VALUE_3 = "PROGRAMMING";
    static final String VALUE_4 = "IT";
    static final String VALUE_5 = "IS";
    static final String VALUE_6 = "FUN";

    @Before
    public void setup() {
        table = new kpcbHashMap<>(10);
        table.set(KEY_1, VALUE_1);
        table.set(KEY_2, VALUE_2);
        table.set(KEY_3, VALUE_3);
        table.set(KEY_4, VALUE_4);
        table.set(KEY_5, VALUE_5);
        table.set(SAMEHASH1, VALUE_1);
        table.set(SAMEHASH2, VALUE_2);
        table.set(SAMEHASH3, VALUE_3);
        table.set(SAMEHASH4, VALUE_4);
        table.set(SAMEHASH5, VALUE_5);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testExceptionSize() {
        table = new kpcbHashMap<>(-1);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testNullKeyGet() {
        table.get(null);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testNullKeySet() {
        table.set(null, "hahah");
    }

    @Test(expected = IllegalArgumentException.class)
    public void testNullKeyDelete() {
        table.delete(null);
    }

    @Test
    public void testSetSingleElement() {
        table = new kpcbHashMap<>(1);
        table.set("HAHAHA", "KPCBFELLOWS");
        assertEquals("KPCBFELLOWS", table.get("HAHAHA"));
    }

    @Test
    public void testSetDeleteSingleElement() {
        table = new kpcbHashMap<>(1);
        table.set("HAHAHA", "KPCBFELLOWS");
        assertEquals("KPCBFELLOWS", table.get("HAHAHA"));
        assertTrue(table.delete("HAHAHA"));
        assertEquals(null, table.get("HAHAHA"));
        assertFalse(table.delete("HAHAHA"));
    }

    @Test
    public void testSetMultipleElement() {
        assertEquals(VALUE_1, table.get(KEY_1));
        assertEquals(VALUE_2, table.get(KEY_2));
        assertEquals(VALUE_3, table.get(KEY_3));
        assertEquals(VALUE_4, table.get(KEY_4));
        assertEquals(VALUE_5, table.get(KEY_5));
    }

    @Test
    public void testSetDeleteMultipleElement() {
        table.delete(KEY_1);
        table.delete(KEY_2);
        table.delete(KEY_3);
        assertEquals(null, table.get(KEY_1));
        assertEquals(null, table.get(KEY_2));
        assertEquals(null, table.get(KEY_3));
        assertEquals(VALUE_4, table.get(KEY_4));
        assertEquals(VALUE_5, table.get(KEY_5));

    }
    

    @Test
    public void testSetOverideElement() {
        assertEquals(VALUE_1, table.get(KEY_1));
        assertEquals(VALUE_2, table.get(KEY_2));
        table.set(KEY_1, "WHAT");
        assertEquals("WHAT", table.get(KEY_1));
        assertEquals(VALUE_2, table.get(KEY_2));

    }

    @Test
    public void testSetSameHashCodeElement() {
        assertEquals(VALUE_1, table.get(SAMEHASH1));
        assertEquals(VALUE_2, table.get(SAMEHASH2));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_4, table.get(SAMEHASH4));
        assertEquals(VALUE_5, table.get(SAMEHASH5));
    }

    @Test
    public void testDeleteSameHashCodeHeadElement() {
        assertTrue(table.delete(SAMEHASH1));
        assertEquals(null, table.get(SAMEHASH1));
        assertEquals(VALUE_2, table.get(SAMEHASH2));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_4, table.get(SAMEHASH4));
        assertEquals(VALUE_5, table.get(SAMEHASH5));

        assertTrue(table.delete(SAMEHASH2));
        assertEquals(null, table.get(SAMEHASH2));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_4, table.get(SAMEHASH4));
        assertEquals(VALUE_5, table.get(SAMEHASH5));

    }

    @Test
    public void testDeleteSameHashAllElement() {
        assertTrue(table.delete(SAMEHASH1));
        assertTrue(table.delete(SAMEHASH2));
        assertTrue(table.delete(SAMEHASH3));
        assertTrue(table.delete(SAMEHASH4));
        assertTrue(table.delete(SAMEHASH5));
        assertTrue(table.delete(KEY_1));
        assertTrue(table.delete(KEY_2));
        assertTrue(table.delete(KEY_3));
        assertTrue(table.delete(KEY_4));
        assertTrue(table.delete(KEY_5));
        assertFalse(table.delete(SAMEHASH1));
        assertFalse(table.delete(SAMEHASH2));
        assertFalse(table.delete(SAMEHASH3));
        assertFalse(table.delete(SAMEHASH4));
        assertFalse(table.delete(SAMEHASH5));
        assertEquals(null, table.get(SAMEHASH1));
        assertEquals(null, table.get(SAMEHASH2));
        assertEquals(null, table.get(SAMEHASH3));
        assertEquals(null, table.get(SAMEHASH4));
        assertEquals(null, table.get(SAMEHASH5));
        assertEquals(null, table.get(KEY_1));
        assertEquals(null, table.get(KEY_2));
        assertEquals(null, table.get(KEY_3));
        assertEquals(null, table.get(KEY_4));
        assertEquals(null, table.get(KEY_5));

    }

    @Test
    public void testDeleteSameHashCodeTailElement() {
        assertTrue(table.delete(SAMEHASH5));
        assertEquals(VALUE_1, table.get(SAMEHASH1));
        assertEquals(VALUE_2, table.get(SAMEHASH2));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_4, table.get(SAMEHASH4));
        assertEquals(null, table.get(SAMEHASH5));

        assertTrue(table.delete(SAMEHASH4));
        assertEquals(VALUE_1, table.get(SAMEHASH1));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_2, table.get(SAMEHASH2));
        assertEquals(null, table.get(SAMEHASH4));

    }

    @Test
    public void testDeleteSameHashCodeHeadANDTailElement() {
        assertTrue(table.delete(SAMEHASH5));
        assertTrue(table.delete(SAMEHASH1));
        assertTrue(table.delete(SAMEHASH2));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_4, table.get(SAMEHASH4));
        assertEquals(null, table.get(SAMEHASH5));
        assertEquals(null, table.get(SAMEHASH1));
        assertEquals(null, table.get(SAMEHASH2));

    }

    @Test
    public void testDeleteSameHashDeleteAndSetlElementWithOverride() {
        assertTrue(table.delete(SAMEHASH5));
        assertTrue(table.delete(SAMEHASH1));
        assertTrue(table.delete(SAMEHASH2));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_4, table.get(SAMEHASH4));
        assertEquals(null, table.get(SAMEHASH5));
        assertEquals(null, table.get(SAMEHASH1));
        assertEquals(null, table.get(SAMEHASH2));

        assertTrue(table.set(SAMEHASH5, VALUE_5));
        assertEquals(VALUE_5, table.get(SAMEHASH5));

        assertTrue(table.set(SAMEHASH1, VALUE_1));
        assertEquals(VALUE_1, table.get(SAMEHASH1));

        assertTrue(table.delete(SAMEHASH1));
        assertEquals(null, table.get(SAMEHASH1));

        assertTrue(table.set(SAMEHASH1, VALUE_5));
        assertTrue(table.set(SAMEHASH2, VALUE_4));
        assertTrue(table.set(SAMEHASH3, VALUE_3));
        assertTrue(table.set(SAMEHASH4, VALUE_2));
        assertTrue(table.set(SAMEHASH5, VALUE_1));
        assertEquals(VALUE_1, table.get(SAMEHASH5));
        assertEquals(VALUE_2, table.get(SAMEHASH4));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_4, table.get(SAMEHASH2));
        assertEquals(VALUE_5, table.get(SAMEHASH1));
    }
    
    @Test
    public void testSetDeleteGetAtWillWithNull() {
        assertTrue(table.delete(SAMEHASH5));
        assertTrue(table.delete(SAMEHASH1));
        assertTrue(table.delete(SAMEHASH2));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_4, table.get(SAMEHASH4));
        assertEquals(null, table.get(SAMEHASH5));
        assertEquals(null, table.get(SAMEHASH1));
        assertEquals(null, table.get(SAMEHASH2));

        assertTrue(table.set(SAMEHASH5, null));
        assertEquals(null, table.get(SAMEHASH5));
        assertTrue(table.delete(SAMEHASH5));

        assertTrue(table.set(KEY_2, VALUE_1));
        assertEquals(VALUE_1, table.get(KEY_2));
        assertTrue(table.set(KEY_5, VALUE_1));
        assertEquals(VALUE_1, table.get(KEY_5));

        assertTrue(table.delete(KEY_2));
        assertEquals(null, table.get(KEY_2));

        assertTrue(table.set(SAMEHASH1, VALUE_5));
        assertTrue(table.set(SAMEHASH2, VALUE_4));
        assertTrue(table.set(SAMEHASH3, VALUE_3));
        assertTrue(table.set(SAMEHASH4, VALUE_2));
        assertTrue(table.set(SAMEHASH5, null));
        assertEquals(null, table.get(SAMEHASH5));
        assertEquals(VALUE_2, table.get(SAMEHASH4));
        assertEquals(VALUE_3, table.get(SAMEHASH3));
        assertEquals(VALUE_4, table.get(SAMEHASH2));
    }
    
    @Test
    public void testOverload() {
        assertTrue(table.set(SAMEHASH1, VALUE_1));
        assertTrue(table.set(SAMEHASH2, VALUE_2));
        assertTrue(table.set(SAMEHASH3, VALUE_3));
        assertFalse(table.set("lol", VALUE_3));
        assertFalse(table.set("lol1", VALUE_3));
        assertFalse(table.set("lol2", VALUE_3));
        assertTrue(table.set(SAMEHASH5, VALUE_3));
        assertEquals(null, table.get("lol"));
        assertEquals(null, table.get("lol2"));
        assertEquals(null, table.get("lol3"));
        assertEquals(VALUE_3, table.get(SAMEHASH5));
        assertEquals(VALUE_1, table.get(SAMEHASH1));
        assertEquals(VALUE_2, table.get(SAMEHASH2));
    }
    
    
    @Test
    public void testOverloadDelte() {
        assertTrue(table.set(SAMEHASH1, VALUE_1));
        assertTrue(table.set(SAMEHASH2, VALUE_2));
        assertTrue(table.set(SAMEHASH3, VALUE_3));
        assertFalse(table.set("lol", VALUE_3));
        assertFalse(table.set("lol2", VALUE_3));
        assertTrue(table.delete(KEY_5));
        assertTrue(table.delete(SAMEHASH1));
        assertTrue(table.delete(SAMEHASH2));
        assertTrue(table.delete(SAMEHASH3));
        assertTrue(table.set("lol", VALUE_3));
        assertTrue(table.set("lol2", VALUE_3));
        assertTrue(table.set("lol3", VALUE_4));
        assertEquals(VALUE_3, table.get("lol"));
        assertEquals(VALUE_3, table.get("lol2"));
        assertEquals(VALUE_4, table.get("lol3"));
    }
    
    
    @Test
    public void testLoadFactorSimple() {
      assertEquals(1.0, table.load(), 0.00000001);
    }
    
    @Test
    public void testLoadFactorEmpty() {
        table = new kpcbHashMap<>(111);
        assertEquals(0, table.load(), 0.00000001);
    }
    
    @Test
    public void testLoadFactorDeleteEmpty() {
        table.delete(KEY_1);
        table.delete(KEY_2);
        table.delete(KEY_3);
        table.delete(KEY_4);
        table.delete(KEY_5);
        table.delete(SAMEHASH1);
        table.delete(SAMEHASH2);
        table.delete(SAMEHASH3);
        table.delete(SAMEHASH4);
        table.delete(SAMEHASH5);
        assertEquals(0, table.load(), 0.00000001);
    }
    
    @Test
    public void testLoadFactorDeleteThree() {
        table.delete(KEY_1);
        table.delete(SAMEHASH1);
        table.delete(SAMEHASH5);
        assertEquals((float)7/10, table.load(), 0.00000001);
    }
    
    @Test
    public void testLoadFactorDeleteHalf() {
        table.delete(KEY_1);
        table.delete(SAMEHASH1);
        table.delete(SAMEHASH5);
        table.delete(SAMEHASH5);
        table.delete(SAMEHASH2);
        table.delete(SAMEHASH4);
        table.delete(SAMEHASH5);
        assertEquals((float)5/10, table.load(), 0.00000001);
    }
    
    @Test
    public void testLoadFactorSetWithDeleteHalf() {
        table.set(KEY_1, "GG");
        table.set(KEY_1, "GG");
        table.set(KEY_1, "GG");
        table.set(SAMEHASH1, "GG");
        table.set(SAMEHASH2, "GG");
        table.set(SAMEHASH3, "GG");
        table.set("LOL", "GG");
        table.delete(KEY_1);
        table.delete(SAMEHASH1);
        table.delete(SAMEHASH5);
        table.delete(SAMEHASH5);
        table.delete(SAMEHASH2);
        table.delete(SAMEHASH4);
        table.delete(SAMEHASH5);
        table.set("LOL", "GG");
        table.set("LOL1", "GG");
        assertEquals((float)7/10, table.load(), 0.00000001);
    }

}
