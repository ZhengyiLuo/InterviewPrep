
/**
 * @Time: Nov 2, 2016
 * @Author: zen
 */

public class LeetCodeSolu6 {
    // Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public class Solution {
        public int maxPathSum(TreeNode root) {
            if (root == null) {
                return 0;
            }
            if (root.left == null && root.left == null) {
                return root.val;

            }
            int leftMaxPath = maxPathSum(root.left);
            int rightMaxPath = maxPathSum(root.right);
            int pathcombine = pathCombine(root);

            return Math.max(Math.max(leftMaxPath, rightMaxPath), pathcombine);

        }

        public int pathCombine(TreeNode root) {
            int leftMax = findMax(root.left, 0);
            int rightMax = findMax(root.right, 0);

            return leftMax + rightMax + root.val;
        }

        public int findMax(TreeNode root, int max) {
             if(root == null){
                 return max;
                 
             }
             if(root.left == null && root.right == null){
                 return root.val + max;
             }
             
             int leftMax = findMax(root.left, root.val+max);
             int rightMax = findMax(root.right,root.val+max);
             
             return Math.max(leftMax, rightMax);
             
             
         }

    }
}
