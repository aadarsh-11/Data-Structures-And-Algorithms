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

struct cmp
{
    bool operator() (ListNode* a, ListNode* b)
    {
        return  a->val > b->val;
    }    
};

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, cmp> pq;
        for(auto i: lists)
        {
            if(i)
            pq.push(i);
        }
        ListNode* head = new ListNode(), *ans;
        ans = head;
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            if(x->next)
                pq.push(x->next);
            head->next = new ListNode(x->val);
            head = head->next;
        }
        return ans->next;
    }
};