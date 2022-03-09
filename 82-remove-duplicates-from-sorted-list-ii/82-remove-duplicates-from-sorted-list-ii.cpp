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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = new ListNode(INT_MIN, head);
        ListNode* ans = pre;
        while(head)
        {
            bool flag = 0;
            while(head and head->next and head->val == head->next->val)
            {
                ListNode* temp = head;
                head = head->next;
                temp = NULL;
                delete(temp);
                flag = 1;
            }
            if(flag)
            {
                ListNode* temp = head;
                head = head->next;
                pre->next = head;
                temp = NULL;
                delete(temp);
            }
            else
            {
                pre = head;
                head = head->next;
            }
        }
        return ans->next;
    }
};