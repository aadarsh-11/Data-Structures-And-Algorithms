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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* ans = head, *prev = head->next, *temp = prev;
        while(head->next)
        {
            head->next = prev->next;
            if(head->next)
            {
                head = head->next;
                prev->next = head->next;
                prev = prev->next;
            }
        }
        head->next = temp;
        return ans;
    }
};