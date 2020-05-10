func permute(nums []int) [][]int {
    if len(nums) == 1 {
        return [][]int{nums}
    }

    res := [][]int{}

    for i, num := range nums {
        // ��num�� nums �ó�ȥ �õ�tmp
        tmp := make([]int, len(nums)-1)
        copy(tmp[0:], nums[0:i])
        copy(tmp[i:], nums[i+1:])

        // sub �ǰ�num �ó�ȥ��������ʣ�����ݵ�ȫ����
        sub := permute(tmp)
        for _, s := range sub {
            res = append(res, append(s, num))
        }
    }
    return res
}