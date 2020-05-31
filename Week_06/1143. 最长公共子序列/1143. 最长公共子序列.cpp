class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int cols = text2.size();
        vector<int> dp(cols, 0);
        // һ���Խ�text1�ĵ�ǰ�ַ�ֵȡ�����������ظ��������
        // �Ż�����������˫100%���������û��� ORZ
        for (const auto ti : text1) {
            int last = dp[0];
            if (ti == text2[0]) {
                dp[0] = 1;
            }

            for (int j = 1; j < cols; j++) {
                if (ti == text2[j]) {
                    swap(dp[j], last);
                    dp[j]++;
                } else {
                    last = dp[j];
                    if (dp[j - 1] > dp[j])
                        dp[j] = dp[j - 1];
                }
            }
        }
        return dp[cols - 1];
    }
};