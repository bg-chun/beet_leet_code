//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        // brute force
        // time complexity is O(N^)
        // space complexity is O(1) since we dont use additional space
        /*for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j< nums.size(); j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
        }
        return ret;*/
        
        
        /*// try to do something better
        // the time complexity of this approach: O(n)
        // the space complexity of this approach: O(n)
        
        // here we defines map that makes me able to check whether sub exists or not in O(1) time complexity.
        // I`ve used map as hash table.
        map<int, int> workspace;
        
        // visit whole vector once to build map, this would be O(n) time complexity.
        for (int i = 0; i < nums.size(); i++)
        {
            // we map value of visiting element to the index of element.
            workspace[nums[i]] = i;
        }
        
        // visit again with checking whether sub exists or not, this also would be O(n) time complexity.
        for (int i = 0; i < nums.size(); i++)
        {
            int sub = target - nums[i];
            
            //using `> 0` is ok here, because we check the first element as the first case.
            if (workspace[sub] > 0 && workspace[sub] != i)
            {
                ret[0] = i;
                ret[1] = workspace[sub];
                return ret;
            }
            
        }
        
        return ret;*/
        
        
        //I think we can do this in single iteration.
        map<int, int> workspace;
        for (int i = 0; i< nums.size(); i++)
        {
            int sub = target - nums[i];
            
            
            if (workspace[sub] != 0 && workspace[sub]-1 != i)
            {
                ret[0] = i;
                ret[1] = workspace[sub]-1;
                return ret;
            }
            
            //give offset
            workspace[nums[i]] = i+1;
        }
        
        return ret;
        
    }
};
