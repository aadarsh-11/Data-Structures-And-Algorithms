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
    ListNode* res = NULL;
    ListNode* rev(ListNode* head,ListNode* last, int k)
    {
        if(!head) return head;
        ListNode* temp = head, *curr = head;
        int cnt = 0;
        while(temp)
        {
            cnt++;
            if(cnt == k)
                break;
            temp = temp->next;
        }
        if(cnt < k)
            return temp;
        
        ListNode* next;
        ListNode* nextHead= temp->next; //3
        ListNode* pre = nextHead;//3
        while(cnt--)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        if(last)
        last->next = pre;
        if(!res) res = pre;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* x = rev(head, NULL, k);
        while(x)
        {
            x= rev(x->next,x,k);
        }
        return res;
    }
};