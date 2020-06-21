//双指针
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

//2.dp写法，觉得好难，有好多情况要考虑
class Solution {
public:
     bool k_validPalindrome(string s, int k){
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0x3f3f3f3f)); // 只需要用前后两行就好，0x3f3f3f3f拟定的无穷大，足够大也不容易溢出

        for (int i = 0; i <= n; ++ i) dp[0][i] = i; // 初始化,显然将t[:i-1]修改为空串需要i次操作
        
        for (int i = 1; i <= n; ++ i){
            dp[i & 1][0] = i; // 类似上述的初始化，只是在这里才赋值
            int from = max(1, i - k), to = min(n, i + k); // k是可以修改的次数,我们可以往前或者往后修改
            for (int j = from; j <= to; ++ j){
                if (s[i - 1] == s[n - j]) dp[i & 1][j] = dp[(i - 1) & 1][j - 1]; // 参看图中i = c, j = c
                dp[i & 1][j] = min({dp[i & 1][j], dp[(i - 1) & 1][j] + 1, dp[i & 1][j - 1] + 1}); // 从i - 1处和j - 1处转移
            }
        }
        return dp[n & 1][n] <= 2 * k; // 对原字符串的一次修改，反映在两个字符串上是两次。为了让s, t相同删除k代表可以对每个操作k次,共2*k
    }
    bool validPalindrome(string s) {
        return k_validPalindrome(s, 1);
    }
};