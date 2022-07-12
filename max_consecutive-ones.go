//https://leetcode.com/problems/max-consecutive-ones/
func findMaxConsecutiveOnes(nums []int) int {
    cnt := 0
    prv := -1
    max := 0
    for _, num := range nums {
        if (num == 1 && prv == -1) || (num ==1 && prv == 1) {
            cnt++
        } else {
            cnt = 0
        }
        
        if cnt > max {
            max = cnt
        }
    }
    
    return max
}
