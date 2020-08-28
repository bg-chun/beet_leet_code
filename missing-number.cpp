//https://leetcode.com/problems/missing-number
class Solution {
public:
    /*int missingNumber(vector<int>& nums) {
        
        //approach A
        // sorting given array O(nlogn)
        // and find missing one O(n)
        // time complexity is O(nlogn)
        // space complexity is O(1)
        int marker = -1;
        
        sort(nums.begin(), nums.end());
        
        if (nums[0] != 0)
        {
            return 0;
        }
        
        if (nums[nums.size()-1] != nums.size())
        {
            return nums.size();
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != marker +1)
            {
                return marker+1;
            }
            
            marker++;
        }
        
        // if given array is [0], the answer is 1.
        // if given array is [0, 1, 2], the answer is 3.
        //return marker+1;
        // in this case the problem allows -1
        return -1;
    }*/
    
    /*int missingNumber(vector<int>& nums) {
        // approach B
        // add all elements of array to map
        // check that which number is missing.
        // time complexity will be O(n), almost O(2xN)
        // space complexity will be O(n)
        
        // add all elements of array to map
        map<int, bool> myMap;
        
        for (int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]] = true;
        }
        
        // check that which number is missing.
        for (int i = 0; i < nums.size(); i++)
        {
            if (myMap[i] == false)
            {
                return i;
            }
        }
        
        return nums.size();
    }*/
    
    int missingNumber(vector<int>& nums) {
        // Approach C
        
        // XOR is shortest way to find missing element.
        // XOR(N(size), every index, every value)
        
        // index: 0, 1, 2, 3
        // value: 0, 1, 3, 4
        
        // XOR(4, 0, 0, 1, 1, 2, 3, 3, 4)
        // =>2
        
        // if every number exist in array, result will be N
        // XOR(4, 0, 0, 1, 1, 2, 2, 3, 3) => 4
        
        
        // 0: 0000
        // 1: 0001
        // 2: 0010
        // 3: 0011
        // 4: 0100
        // 5: 0101
        // 6: 0110
        // 7: 0111
        
        int missing_one = nums.size();
        
        for (int i = 0; i < nums.size(); i++)
        {
            missing_one ^= i ^ nums[i];
        }
        
        return missing_one;
    }
};
