func plusOne(digits []int) []int {
    add := 1
    for length := len(digits)-1; length >= 0 && add > 0; length-- {
        sum := digits[length] + add
        add = sum / 10
        digits[length] = sum % 10
    }
    
    if add > 0 {
        digits = append([]int{add}, digits...)
    }
    return digits
}