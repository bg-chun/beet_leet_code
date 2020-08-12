//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    /*vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> workspace;
        vector<int> ret(2);
        int i;
        int sub;
        
        //time complexity here would be O(n)
        for (i = 0; i < numbers.size(); i++)
        {
            sub = target - numbers[i];
            
            // if sub exists in the hash and it is not equal to visiting element
            if (workspace[sub] > 0 && workspace[sub] != i +1)
            {
                //return indexes in non-zero-based
                ret[0] = i+1;
                ret[1] = workspace[sub];
                
                //when we found answer, we sort vectore, so it bring us O(logn)
                //so total time complexity would be neer O(n), more precisely it would be O(n/*the iteration of input*/ //+ logn/*sorting*/)
                /*std::sort(ret.begin(), ret.end());
                return ret;
            }

            workspace[numbers[i]] = i+1;
        }
        
        return ret;
    }*/
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret(2);
        
        // here we try to beat this problem in O(N)
        // this approach would work for only sorted input so if given array is not sorted we should sort the array first.
        // we need two pointers to find answer.
        
        int low = 0, high = numbers.size() -1;
        
        while(low < high/*low should not exceed high*/ && numbers[low] <= target/*if low exceeds target there is no answer*/)
        {
            // if the sum is greater than the target, we should move high pivot to it`s left.
            if (numbers[low] + numbers[high] > target)
            {
                high--;
                continue;
            }
            // if the sum is less than the target, we should move low pivot to it`s right.
            else if (numbers[low] + numbers[high] < target)
            {
                low++;
                continue;
            }
            // otherwise, we've found answer :)
            else
            {
                ret[0] = low + 1;
                ret[1] = high + 1;
                return ret;
            }
        }
        
        return ret;
        
    }
};
