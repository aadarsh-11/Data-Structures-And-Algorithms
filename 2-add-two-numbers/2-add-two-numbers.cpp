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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1,s2;
        while(l1)
        {
            s1 += to_string(l1->val);
            l1 = l1->next;
        }
        
        while(l2)
        {
            s2 += to_string(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        
        for(int i = 0 ; i < max(s1.size(), s2.size()) or carry>0; i++)
        {
            int x = carry;
            if(i<s1.size())
            {
                x += s1[i]-'0';
            }
            if(i<s2.size())
            {
                x += s2[i]-'0';
            }
            carry = x/10;
            x %= 10;
            head->val = x;
            if(carry>0 or i<max(s1.size(), s2.size())-1)
            {
                head->next = new ListNode();
            }
            else
            {
                head->next = NULL;
            }
            head = head->next;
        }
        return ans;
    }
};