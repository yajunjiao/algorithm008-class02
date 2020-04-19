func twoSum(nums []int, target int) []int {
    maps := make(map[int]int)
	result := make([]int, 0)
	for index, num := range nums {
		_, isTrue := maps[target - num]
		if isTrue {
			result = append(result, maps[target - num])
			result = append(result, index)
			break
		}
		maps[num] = index
	}
	return result
}