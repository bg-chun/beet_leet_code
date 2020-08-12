//https://leetcode.com/problems/greatest-common-divisor-of-strings/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
  
        if (str1.size() == 0  && str2.size() == 0)
        {
            return "";
        }
        else if (str1.size() == 0 && str2.size() != 0)
        {
            return str1;
        }
        else if (str1.size() != 0 && str2.size() == 0)
        {
            return str2;
        }
        else if (str1.size() == str2.size() && str1.compare(str2) == 0)
        {
            //if they are exactly same, return one of them.
            return str1;
        }
        else //run gcd here
        {
            return gcd(str1, str2);
        }
        return "";
    }
    
    string gcd(string str1, string str2)
    {
        if (str1.size() < str2.size())
        {
            return gcd(str2, str1);
        }
        if (str1.size()== str2.size())
        {
            if (str1.compare(str2) == 0)
            {
                return str1;
            }
            
            return "";
        }
        //substr(pos, len)
        return gcd(str2, str1.substr(str2.size(), str1.size() - str2.size()));
    }
};
