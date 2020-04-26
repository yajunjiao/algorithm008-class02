class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
       List<Integer> ans = new ArrayList<>();
       TreeNode curr = root;
       TreeNode pre;
       while(curr != null) {
           if(curr.left == null) {
               ans.add(curr.val);
               curr = curr.right;
           } else {
               pre = curr.left;
               while (pre.right != null) {
                   pre = pre.right;
               }
               pre.right = curr;
               TreeNode temp = curr;
               curr = curr.left;
               temp.left = null;
           }
       }
       return ans;
    }
    /*
        //�ڶ��ֽⷨ
        List<Integer> ans = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        while(curr != null || !stack.isEmpty()) {
            while(curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            ans.add(curr.val);
            curr = curr.right;
        }
        return ans;
        */
        
    /*
        ��һ�ֽⷨ
        List<Integer> res = new ArrayList<>();
        helper(root, res);
        return res;
        */
    
    /*
    public void helper(TreeNode root, List<Integer> res) {
        if(root != null) {
            if(root.left != null) {
               helper(root.left, res);
            }
            res.add(root.val);
            if(root.right != null) {
                helper(root.right, res);
            }
        }
    }
    */
}