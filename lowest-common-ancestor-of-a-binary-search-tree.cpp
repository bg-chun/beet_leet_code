//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // time complexity will be O(N)
    // space complexity will be O(N), since this resursive approach consumes memory for stack.
    /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // case1: both are on the left
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        
        // case2: both are on the right
        if (p->val > root->val && q->val > root->val )
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        
        // case3: answer!
        return root;
    }*/
    
    // time complexity will be O(N)
    // space complexity will be O(1), since we dont use memory for stack here.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL)
        {
            // p and q exist on the left
            if (p->val < root->val && q->val < root->val)
            {
                root = root->left;
                continue;
            }
        
        
            // p and q exist on the right
            if (p->val > root->val && q->val > root->val )
            {
                root = root->right;
                continue;
            }
            
            // otherwise this is answer!
            return root;
        }
        
        return NULL;
    }
};
