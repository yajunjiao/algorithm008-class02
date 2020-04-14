func moveZeroes(nums []int)  {
    temp := 0
    lastFindZero := 0
	for cur := 0 ; cur < len(nums) ; cur++ {
            if nums[cur] != 0 {
                temp = nums[lastFindZero]
                nums[lastFindZero] = nums[cur]
                nums[cur] = temp
                lastFindZero++;
            }
	}
	return
}