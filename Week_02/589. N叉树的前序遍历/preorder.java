class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> ans = new LinkedList<>();
        helper(root, ans);
        return ans;
    }

    public void helper(Node root, List<Integer> ans) {
        if(root != null){
            ans.add(root.val);
            for(Node node : root.children) {
                helper(node, ans);
            }
        }
    }
}