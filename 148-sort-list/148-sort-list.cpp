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
    ListNode* merge(ListNode* fhead, ListNode* shead)
    {
        ListNode* ans, *curr;
        if(fhead->val <= shead->val)    
        {
            ans = fhead;
            curr = fhead;
            fhead = fhead->next;
        }
        else
        {
            ans = shead;
            curr = shead;
            shead = shead->next;
        }
        
        while(fhead and shead)
        {
             if(fhead->val <= shead->val)    
            {
                curr->next = fhead;
                fhead = fhead->next;
            }
            else
            {
                curr->next = shead;
                shead = shead->next;
            }
             curr = curr->next;
        }
        if(fhead)
        {
            curr->next = fhead;
        }
        else
        {
            curr->next = shead;
        }
        return ans;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        if(!head->next->next)
        {
            if(head->val > head->next->val)
            {
                ListNode* new_head = head->next;
                new_head->next = head;
                head->next = NULL;
                return new_head;
            }
            return head;
        }
        ListNode* fhead = head;
        ListNode* slow = head, *fast = head;
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* shead = slow->next;
        slow->next = NULL;
        fhead = sortList(fhead);
        shead = sortList(shead);
        
        return merge(fhead,shead);
    }
};