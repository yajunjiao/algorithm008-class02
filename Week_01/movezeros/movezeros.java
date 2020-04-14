class Solution {
    public void moveZeroes(int[] nums) {
        int temp = 0;
        for(int lastFindZero = 0, cur = 0; cur < nums.length; cur++) {
            if(nums[cur] != 0) {
                temp = nums[lastFindZero];
                nums[lastFindZero] = nums[cur];
                nums[cur] = temp;
                lastFindZero++;
            }
        }
    }
}