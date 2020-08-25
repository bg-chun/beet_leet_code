//https://leetcode.com/problems/high-five

class Solution {
public:
    
    //time complexity will be O(N).
    //space complexity will be O(N).
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> myMap;
        vector<vector<int>> ret;
        
        for (int i = 0; i< items.size(); i++)
        {   
            (myMap[items[i][0]]).push_back(items[i][1]);
            
        }
        
        for (auto itr = myMap.begin(); itr != myMap.end(); itr++)
        {
            int avr = 0;
            sort((itr->second).begin(), (itr->second).end(), [](int a, int b){return  a > b;});
            
            for (int i = 0; i < 5; i++)
            {
                avr += (itr->second)[i];
            }
            
            
            ret.push_back(vector<int>{itr->first, avr/5});
        }
        
        return ret;
        
    }
};
