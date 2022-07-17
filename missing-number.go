func missingNumber(nums []int) int {
    sort.Ints(nums)
    
    for i, v := range nums {
        if i != v {
            return i
        }
    }
    return len(nums)
}
