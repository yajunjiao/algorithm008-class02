class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int temp = 0;
        for(int lastFindZero = 0, cur = 0; cur < nums.size(); cur++) {
            if(nums[cur]) { //nums[cur] != 0
                swap(nums[lastFindZero++], nums[cur]);
               /*
                temp = nums[lastFindZero];
                nums[lastFindZero] = nums[cur];
                nums[cur] = temp;
                lastFindZero++;*/
            }
        }
    }
};