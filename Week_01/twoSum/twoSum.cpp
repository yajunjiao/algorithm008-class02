class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> strMap;
        vector<int> ans{0, 0};
        for(int cur = 0; cur < nums.size(); cur++) {
            strMap.insert(map<int ,int>::value_type(nums[cur], cur)); 
        }
        int temp = 0;
        for(int i = 0; i < nums.size(); i++) {
            temp = target - nums[i];
            if(strMap.count(temp) != 0 && strMap[temp] != i) {
                ans[0] = i;
                ans[1] = strMap[temp];
                i = nums.size();
            }
        }
        return ans;
    }
};