func rotate(nums []int, k int)  {
    k %= len(nums)
    reverse(nums, 0, len(nums) - 1)
    reverse(nums, 0, k - 1)
    reverse(nums, k, len(nums) - 1)
}

func reverse(nums []int, start int, end int) {
    temp := 0
    for start < end {
        temp = nums[start]
        nums[start] = nums[end]
        nums[end] = temp
        start++;
        end--;
    }
}