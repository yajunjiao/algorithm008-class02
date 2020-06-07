class Solution {
public:
    int climbStairs(int n) {
        if (n < 4) return n;
        int ans = 0;
        int f1= 1, f2 = 2, f3 = 3;
        for(int i = 4; i <= n; ++i) {
            ans = f3 + f2;
            f2 = f3;
            f3 = ans;
        }
        return ans;
    }
};