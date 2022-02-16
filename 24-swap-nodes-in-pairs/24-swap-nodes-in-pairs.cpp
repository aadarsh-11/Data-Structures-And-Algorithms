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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        
        ListNode* curr = head;
        ListNode* nxt = curr->next;
        
        if(!nxt) return head;
        curr->next = swapPairs(nxt->next);
        nxt->next = curr;
        
        return nxt;
    }
};