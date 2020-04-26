class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(Node* root, vector<int>& ans) {
        if(root) {
            ans.push_back(root->val);
            for(auto node : root->children) {
                helper(node, ans);
            }
        }
    }
};