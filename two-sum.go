func twoSum(nums []int, target int) []int {
    myMap := make(map[int]int)
    ret := make([]int, 2, 2)

    for i, v := range nums {
        myMap[v] = i
    }
    
    for i, v := range nums {
        if _, ok := myMap[target - v]; ok && i != myMap[target - v] {
            ret[0] = i
            ret[1] = myMap[target -v]
            return ret
        }
    }
    
    return ret
}
