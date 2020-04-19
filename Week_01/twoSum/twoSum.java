class Solution {
    public int[] twoSum(int[] nums, int target) {
         /* int[] ans = new int[2];
        for(int l = 0; l < nums.length; l++) {
            for(int r = nums.length - 1; r > l; r--){
                if(nums[l] + nums[r] == target) {
                    ans[0] = l;
                    ans[1] = r;
                    return ans;
                }
            }
        }*/
        int[] ans = new int[2];
        Map<Integer, Integer> numMap = new HashMap<>();
        for(int cur = 0; cur < nums.length; cur++) {
            numMap.put(nums[cur], cur);
        }
        for(int i = 0; i < nums.length; i++) {
            if(numMap.containsKey(target - nums[i]) && numMap.get(target - nums[i]) != i) {
                ans[0] = i;
                ans[1] = numMap.get(target - nums[i]);
                i = nums.length;
            }
        }
        return ans;
    }
}