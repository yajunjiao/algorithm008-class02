class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) return n;
        vector<int> dp(n, 0);
        dp[1] = 2;
        dp[2] = 3;
        for(int i = 3; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};