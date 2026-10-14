/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int MaxProduct(TreeNode root) {
        var nodes = new List<(TreeNode node, int parent)>{(root, -1)};
        long total = 0;

        for (int i = 0; i < nodes.Count; i++) {
            var node = nodes[i].node;
            total += node.val;

            if (node.left != null)
                nodes.Add((node.left, i));
            
            if (node.right != null)
                nodes.Add((node.right, i));
        }

        var sums = new long[nodes.Count];
        long best = 0;

        for (int i = nodes.Count - 1; i > 0; i--) {
            var (node, parent) = nodes[i];
            long sum = sums[i] + node.val;
            best = Math.Max(best, sum * (total - sum));
            sums[parent] += sum;
        }

        return (int)(best % 1_000_000_007);
    }
}