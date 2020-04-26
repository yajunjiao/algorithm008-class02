class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) {
            return ans;
        }
        std::stack<TreeNode*> treeStack;
        treeStack.push(root);
        while(!treeStack.empty()) {
            TreeNode* node = treeStack.top();
            treeStack.pop();
            if(node) {
                ans.push_back(node->val);
                if(node->right) {
                    treeStack.push(node->right);
                }
                if(node->left) {
                    treeStack.push(node->left);
                }
            }
        }
        return ans;
    }
};