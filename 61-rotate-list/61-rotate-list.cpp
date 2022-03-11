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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        int n = 0;
        do {
            slow = slow->next;
            fast = fast->next->next;
            n += 2;
        } while(fast and fast->next);
        
        if(fast) n++;
        
        k = k%n;
        
        slow = head;
        fast = head;
        
        while(k--)
        {
            fast = fast->next;    
        }
        
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        fast = slow->next;
        slow->next = NULL;
        
        return fast;
    }
};