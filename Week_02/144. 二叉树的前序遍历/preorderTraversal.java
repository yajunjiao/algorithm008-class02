class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        LinkedList<Integer> ans = new LinkedList<>();
        if(root == null) {
            return ans;
        }
        LinkedList<TreeNode> stack = new LinkedList<>();
        stack.add(root);
        while(!stack.isEmpty()) {
            TreeNode node = stack.pollLast();
            ans.add(node.val);
            if(node.right != null) {
                stack.add(node.right);
            }
            if(node.left != null) {
                stack.add(node.left);
            }
        }
        return ans;
    }
}