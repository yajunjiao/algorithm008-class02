//˫ָ��
class Solution {
public:
    bool e = true;
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else if(e) {
                e = false;
                return validPalindrome(s.substr(i + 1, j - i)) || validPalindrome(s.substr(i, j - i));
            }
            else return false;
        }
        return true;
    }
};

//2.dpд�������ú��ѣ��кö����Ҫ����
class Solution {
public:
     bool k_validPalindrome(string s, int k){
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0x3f3f3f3f)); // ֻ��Ҫ��ǰ�����оͺã�0x3f3f3f3f�ⶨ��������㹻��Ҳ���������

        for (int i = 0; i <= n; ++ i) dp[0][i] = i; // ��ʼ��,��Ȼ��t[:i-1]�޸�Ϊ�մ���Ҫi�β���
        
        for (int i = 1; i <= n; ++ i){
            dp[i & 1][0] = i; // ���������ĳ�ʼ����ֻ��������Ÿ�ֵ
            int from = max(1, i - k), to = min(n, i + k); // k�ǿ����޸ĵĴ���,���ǿ�����ǰ���������޸�
            for (int j = from; j <= to; ++ j){
                if (s[i - 1] == s[n - j]) dp[i & 1][j] = dp[(i - 1) & 1][j - 1]; // �ο�ͼ��i = c, j = c
                dp[i & 1][j] = min({dp[i & 1][j], dp[(i - 1) & 1][j] + 1, dp[i & 1][j - 1] + 1}); // ��i - 1����j - 1��ת��
            }
        }
        return dp[n & 1][n] <= 2 * k; // ��ԭ�ַ�����һ���޸ģ���ӳ�������ַ����������Ρ�Ϊ����s, t��ͬɾ��k������Զ�ÿ������k��,��2*k
    }
    bool validPalindrome(string s) {
        return k_validPalindrome(s, 1);
    }
};