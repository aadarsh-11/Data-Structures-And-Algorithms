class Node {
    public:
    int val;
    Node* next[2];
    Node()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

Node* Trie(vector<int> &a)
{
    Node* root = new Node();
    for(auto x:a)
    {
        Node* curr = root;
        for(int i = 31; i>=0; i--)
        {
            int bit = (x>>i)&1;
            if(curr->next[bit])
            {
                curr = curr->next[bit];
            }
            else
            {
                curr->next[bit] = new Node();
                curr = curr->next[bit];
            }
        }
    }
    return root;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = Trie(nums);
        
        int res = 0;
        
        for(auto x: nums)
        {
            int ans = 0;
            Node* curr = root;
            for(int i = 31;i>=0; i--)
            {
                int bit = (x>>i)&1?0:1;
                if(curr->next[bit])
                {
                    ans = ans<<1;
                    ans = ans | 1;
                    curr = curr->next[bit];
                }
                else
                {
                    ans = ans <<1;
                    ans = ans | 0;
                    curr = curr->next[1^bit];
                }
            }
            res = max(res, ans);
        }
        
        return res;
    }
};