import java.util.Stack;

/**
 * @Time: Oct 14, 2016
 * @Author: ZhengyiLuo
 * 
 * 
 *          Suppose we abstract our file system by a string in the following
 *          manner:
 * 
 *          The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 * 
 *          dir subdir1 subdir2 file.ext The directory dir contains an empty
 *          sub-directory subdir1 and a sub-directory subdir2 containing a file
 *          file.ext.
 * 
 *          The string
 *          "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
 *          represents:
 * 
 *          dir subdir1 file1.ext subsubdir1 subdir2 subsubdir2 file2.ext The
 *          directory dir contains two sub-directories subdir1 and subdir2.
 *          subdir1 contains a file file1.ext and an empty second-level
 *          sub-directory subsubdir1. subdir2 contains a second-level
 *          sub-directory subsubdir2 containing a file file2.ext.
 * 
 *          We are interested in finding the longest (number of characters)
 *          absolute path to a file within our file system. For example, in the
 *          second example above, the longest absolute path is
 *          "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not
 *          including the double quotes).
 * 
 *          Given a string representing the file system in the above format,
 *          return the length of the longest absolute path to file in the
 *          abstracted file system. If there is no file in the system, return 0.
 *          
 *          
 *            String input = "a.txt";
        String input2 = "dir\n    file.txt";
        String input3 = "dir\n\t        file.txt\n\tfile2.txt";
        
        LeetCodeSolu2 solu2 = new LeetCodeSolu2();
//        System.out.println(input);
        System.out.println(solu2.lengthLongestPath(input3));
      
 */

public class LeetCodeSolu2 {
    public int lengthLongestPath(String input) {
        Stack<Integer> stack = new Stack<>();
        int maxlength = 0;
        String[] array = input.split("\n");
        stack.push(0);
        for (int i = 0; i < array.length; i++) {

            int level = array[i].lastIndexOf('\t') + 1;
            while (level + 1 < stack.size()) {
                stack.pop();
            }
            int length = array[i].length() - level + stack.peek() + 1;
            if (array[i].contains(".")) {
                maxlength = Math.max(maxlength, length-1);
                continue;
            }
            stack.push(length);
        }

        return maxlength;

    }
}
