class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(), 1);

        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int i = 0;i<nums.size()-2;++i){
            dp[i][i+2] = nums[i]*nums[i+1]*nums[i+2];
        }

        for(int j = 3;j<nums.size();++j){
            for(int i = j-3;i>=0;--i){
                
                for(int k = i+1;k<j;++k){
                    dp[i][j] = max(dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j], dp[i][j]);
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};