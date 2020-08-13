//https://leetcode.com/problems/3sum/

class Solution {
public:
    /*vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmpVector(3);

        vector<int> candidate(3);
        
        map<int, map<int, map<int, bool>>> indexMap;
        map<int, map<int, map<int, bool>>> valueMap;
        
        // Try O(N^3) approach first
        for (int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                for (int k = j; k < nums.size(); k++)
                {
                    if (i != j && j != k && i != k)
                    {
                        if ((nums[i] + nums[j] + nums[k]) == 0)
                        {
                            
                            // check whether duplicated index is used
                            if (indexMap[i][j][k] == true || valueMap[nums[i]][nums[j]][nums[k]] == true)
                            {
                                continue;
                            }
                            
                            //we've found new answer, update maps
                            candidate[0] = i;
                            candidate[1] = j;
                            candidate[2] = k;
                            
                            for (int ii = 0; ii < candidate.size(); ii++)
                            {
                                for (int jj = 0; jj < candidate.size(); jj++)
                                {
                                    for (int kk = 0; kk < candidate.size(); kk++)
                                    {
                                        if (ii != jj && jj != kk && ii != kk)
                                        {
                                            // check all posibility.
                                            indexMap[candidate[ii]][candidate[jj]][candidate[kk]] = true;
                                            valueMap[nums[candidate[ii]]][nums[candidate[jj]]][nums[candidate[kk]]] = true;
                                            
                                        }
                                    }
                                }
                            }

                            
                            tmpVector[0] = nums[i];
                            tmpVector[1] = nums[j];
                            tmpVector[2] = nums[k];
                            ret.push_back(tmpVector);
                        }
                    }
                }
            }
        }
        
        return ret;
    }*/
    
    /*vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int indexOfChoosenNumber;
        
        //do we need hash for index here?
        map<int, map<int, map<int, bool>>> valueHash;
        
        
        // choose one number from nums to make problem to "two sum" so time complexity of this approach would be O(n^)
        for (int i = 0; i < nums.size(); i++)
        {
            indexOfChoosenNumber = i;
            // if we found all numbers that can be added up to 0, 
            vector<int> twoNums(2);
            if (!twoSum(nums, 0 - (nums[indexOfChoosenNumber]), indexOfChoosenNumber, twoNums))
            {
                continue;
            }
            
            // check whether it is duplicated answer.
            if (valueHash[nums[i]][twoNums[0]][twoNums[1]] == true)
            {
                continue;
            }
            
            //add to ret
            vector<int> tmp(3);
            tmp[0] = nums[i];
            tmp[1] = twoNums[0];
            tmp[2] = twoNums[1];
            ret.push_back(tmp);
            
            //update hashs here.
            valueHash[nums[i]][twoNums[0]][twoNums[1]] = true;
            valueHash[nums[i]][twoNums[1]][twoNums[0]] = true;
            
            valueHash[twoNums[0]][nums[i]][twoNums[1]] = true;
            valueHash[twoNums[0]][twoNums[1]][nums[i]] = true;
            
            valueHash[twoNums[1]][nums[i]][twoNums[0]] = true;
            valueHash[twoNums[1]][twoNums[0]][nums[i]] = true;
            
        }
        
        
        return ret;
    }
    
    bool twoSum(vector<int>& nums, int target, int indexOfChoosenNumber, vector<int>& ret)
    {
        map<int, bool> myMap;
        
        //build hash map here
        //for (int i = 0; i<nums.size(); i++)
        //{
        //    myMap[i] = true;
        //}
        for (int i = 0; i<nums.size(); i++)
        {
            if (i == indexOfChoosenNumber)
            {
                continue;
            }

            if (myMap[target - nums[i]] == true && )
            {
                //we've found answer :)
                ret[0] = nums[i];
                ret[1] = target - nums[i];
                return true;
            }
            
        }
        return false;
    }*/
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        //vector<int> tmp;
        //map<int, map<int, map<int, bool>>> hash;
        // the approach is making the problem simpler.
        // so we`re going to make this to be two sum problem set.
        // pick a number and find the other two numbers.
        // for this the given array should be sorted in ascending order.
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                // if the first number is greater than 0 there is no possibility.
                return ret;
            }
            
            if (i > 0 && nums[i-1] == nums[i])
            {
                continue;
            }
            
            //twoSum(nums, i, 0 - nums[i], ret, hash);
            twoSum(nums, i, 0 - nums[i], ret);

            
        }
        
        
        return ret;
    }
    
    //vector<int>
    void twoSum(vector<int>& nums, int picked/*this is the index*/, int target/*this is the value*/, vector<vector<int>>& ret/*, map<int, map<int, map<int, bool>>>& hash*/) {
        //vector<int> tmp;
        
        // The algorithm is:
        // if low + high is greater than the target move high to its left.
        // if low + high is less than the target move low to its right.
        // if low + high is equal to the target this is answer.
        int low = picked+1, high = nums.size() -1;
        //int last_low_num, last_high_num;
        
        while(low < high)
        {
            if ((nums[low] + nums[high]) > target)
            {
                high--;
            }
            else if ((nums[low] + nums[high]) < target)
            {
                low++;
            }
            else // otherwise this is the answer.
            {
                // this hash approach requires O(n^3) space complexity... don`t do this.
                /*if (hash[nums[picked]][nums[low]][nums[high]] != true)
                {
                    ret.push_back(vector<int>{nums[picked], nums[low], nums[high]});
                    hash[nums[picked]][nums[low]][nums[high]] = true;
                }
                
                //find the other answer.
                high--;
                low++;
                continue;*/
                
                ret.push_back(vector<int>{nums[picked], nums[low], nums[high]});
                
                
                low++;
                high--;

                
                //if we found two numbers(the first and second one), we don`t have to repeat these numbers.
                //ex) if the first/second number is `-1` and `0`, the third number is always `1` to be added up to `0`
                //so if you found an answer, you must have to skip the same number for the second element.
                //if the given array is {-3, -1, 0, 1, 1, 1, 1, 1, 1, .........., 1, 2}, then when you found the answer{-3, 1, 2},
                //you should ignore the all of remain `1` as the second element of answer.
                while(low < high && nums[low] == nums[low-1])
                {
                    low++;
                }
                
                
            }
        }
        //return ret;
    }
};
