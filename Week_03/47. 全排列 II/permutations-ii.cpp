class Solution {
public:
   vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int len = nums.size();
        dfs(nums,0,len,ans);
        return ans;
    }

    void dfs(vector<int>& nums,int index,int &len,vector<vector<int>> &ans){
        if(index == len-1)
            ans.push_back(nums);
        unordered_map<int,int> hash;
        for(int i = index;i<len;i++){
            if(hash.count(nums[i]))
                continue;
            else{
                swap(nums[index],nums[i]);
                dfs(nums,index+1,len,ans);
                swap(nums[index],nums[i]);
                hash[nums[i]]=1;
            }
        }
    }
};