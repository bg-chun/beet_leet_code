//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        map<int, bool> hash;
        return preOrder(root, k, hash);
    }
    
    bool preOrder(TreeNode* cur, int target, map<int, bool>& hash)
    {
        if (cur == NULL)
        {
            return false;
        }

        if (preOrder(cur -> left, target, hash))
        {
            return true;
        }
        
        //do sth for cur here
        if (hash[(target - (cur->val))])
        {
            return true;
        }
        else
        {
            hash[(cur->val)] = true;
        }
        
        
        if (preOrder(cur -> right, target, hash))
        {
            return true;
        }
        
        return false;
    }
};
