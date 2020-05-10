class Solution {
public:
    TreeNode* dfs(vector<int>& P, int pi, int pj, vector<int>& Q, int qi, int qj,
              unordered_map<int, int>& M) {
        if (pi >= pj || qi >= qj) return NULL;
        int pos = M[P[pi]] - qi;  // ���������л�ȡ�������ĳ���
        auto root = new TreeNode(P[pi]);
        root->left = dfs(P, pi + 1, pi + pos + 1, Q, qi, qi + pos + 1, M);
        root->right = dfs(P, pi + pos + 1, pj, Q, qi + pos + 1, qj, M);
        return root;
    }
    TreeNode* buildTree(vector<int>& P, vector<int>& Q) {
        unordered_map<int, int> M;  //��¼�����������е�λ��
        for (int i = 0; i < Q.size(); ++i) M[Q[i]] = i;
        return dfs(P, 0, P.size(), Q, 0, Q.size(), M);
    }
};