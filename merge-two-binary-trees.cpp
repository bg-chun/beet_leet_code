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
    /*TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        // all we need to do is overlapping two trees.
        // but how to?
        
        // solution 1
        // visit tree1 and transfrom tree as level order in an array
        // visit tree2 and transfrom tree as level order in an array
        // traverse two transformed arrays together to merge them
        
        // solution 2
        // traverse two tree together with adding up values of trees
        // traberse again merge to trees
        // return merged one
        // time complexity would be O(n) more percisely O(2n)
        // space complexity would be O(1)
        
        TreeNode* ret = NULL;
        
        
        // I usually check input first.
        if (t1 == NULL && t2 == NULL)
        {
            return ret;
        }
        else if (t1 != NULL && t2 == NULL)
        {
            return t1;
        }
        else if (t1 == NULL && t2 != NULL)
        {
            return t2;
        }
        else // otherwise there are real trees :)
        {
            traverseAndMerge(t1, t2);
            makeRet(t1, t2);
        }
        
        return t1;
    }
    
    //preOrder
    void traverseAndMerge(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == NULL & t2 == NULL)
        {
            return;
        }

        // left
        traverseAndMerge(t1 != NULL ? t1->left : NULL, t2 != NULL ? t2->left : NULL);

        // cur
        if (t1 != NULL && t2 != NULL)
        {
            t1->val += t2->val;
        }
        
        // right
        traverseAndMerge(t1 != NULL ? t1->right : NULL, t2 != NULL ? t2->right : NULL);
        return;
    }
    
    void makeRet(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == NULL && t2 == NULL)
        {
            return;
        }
        
        
        // take left
        if (t1 && t1->left == NULL && t2 && t2->left)
        {
            t1->left = t2->left;
        }
        makeRet(t1 != NULL ? t1->left : NULL, t2 != NULL ? t2->left : NULL);
        
        
        // take right
        if (t1 && t1->right == NULL && t2 && t2->right)
        {
            t1->right = t2->right;
        }
        makeRet(t1 != NULL ? t1->right : NULL, t2 != NULL ? t2->right : NULL);
    }*/
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)
        {
            return t2;
        }

        if (t2 == NULL){
            return t1;
        }

        //left
        t1->left = mergeTrees(t1->left, t2->left);
        
        //cur
        t1->val += t2->val;
        
        
        //right
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};
