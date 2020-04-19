class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // std::rotate(nums.begin(), nums.end() - k % nums.size(), nums.end());
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int>& nums, int start, int end) {
        int temp = 0;
        while(start < end) {
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};