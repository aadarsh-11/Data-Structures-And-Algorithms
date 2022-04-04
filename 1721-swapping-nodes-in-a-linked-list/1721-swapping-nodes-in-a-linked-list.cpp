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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = new ListNode(0,head);
        while(head and head->next)
        {
            head = head->next->next;
            n+=2;
        }
        if(head) n++;
        head = temp;
        
        if(n%2 and (n+1)/2 == k) return temp->next;
        
        int x = k-1;
        while(x--)
        {
            head = head->next;
        }
        ListNode* p1 = head;
        
        head = temp;
        x = n - k;
        while(x--)
        {
            head = head->next;
        }
        ListNode* p2 = head;
        
        ListNode* s1 = p1->next;
        ListNode* s2 = p2->next;
        p1->next = s2;
        p2->next = s1;
        
        p1 = s1->next;
        s1->next = s2->next;
        s2->next = p1;
        
        return temp->next;
    }
};