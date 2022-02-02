/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        stack<ListNode*> st,ss;
        while(a)
        {
            st.push(a);
            a =a ->next;
        }
        while(b)
        {
            ss.push(b);
            b = b->next;
        }
        ListNode* ans = nullptr;
        while(!ss.empty() and !st.empty() and ss.top() == st.top())
        {
            ans = ss.top();
            ss.pop();
            st.pop();
        }
        return (ans?ans:NULL);
    }
};