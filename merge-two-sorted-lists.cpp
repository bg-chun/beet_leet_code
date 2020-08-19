//https://leetcode.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// approach 1
        // add them to a new pointer array
        // sort
        // update link
        // return
        // time complexity will be O(N) , actually O(N+ logN+ N)
        // space complexity will be O(N)
        
        // approach 2
        // do recursive
        // add node to the proper position.
        // time complexity will be O(N)
        // space complexity will be O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        
        if (l2 == NULL)
        {
            return l1;
        }
        
        ListNode* head = NULL;
        ListNode* last;
        recursive(l1, l2, head, last);
        
        return head;
    }
    
    void recursive(ListNode* l1, ListNode* l2, ListNode*& head, ListNode*& last)
    {
        if(!l1 && !l2)
        {
            return;
        }
        // 1, 2, 3, 4, 5
        // 1, 3, 5, 7
        if (head == NULL)
        {
            if (l1->val < l2->val)
            {
                last = head = l1; 
                recursive(l1->next, l2, head, last);
            }
            else
            {
                last = head = l2;
                recursive(l1, l2->next, head, last);
            }
        }
        else
        {
            if (l1 && !l2)
            {
                last = last -> next = l1;
                recursive(l1->next, l2, head, last);
                
            }
            else if (!l1 && l2)
            {
                last = last -> next = l2;
                recursive(l1, l2->next, head, last);
            }
            else
            {
                if (l1->val < l2->val)
                {
                    
                    last = last -> next = l1;
                    recursive(l1 -> next, l2, head, last);
                }
                else
                {
                    last = last -> next = l2;
                    recursive(l1, l2->next, head, last);
                }
            }
        }
        
        
        
        
    }
    
    
};
