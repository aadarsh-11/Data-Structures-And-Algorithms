class Node {
    public:
    Node* next[2];
    bool isWord = false;
    Node()
    {
        this->next[0] = NULL;
        this->next[1] = NULL;
    }
};

Node* Trie(vector<int> a)
{
    Node* root = new Node();
    for(auto x: a)
    {
        Node* curr = root;
        for(int i = 31; i>=0; i--)
        {
            int bit = (x>>i)&1;
            if(curr->next[bit] == NULL)
            {
                curr->next[bit] = new Node();
            }
            curr = curr->next[bit];
        }
    }
    return root;
}


class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        Node* root = Trie(a);
        int fans = 0;
        for(auto x: a)
        {
            // cout<<x<<": \n";
            int ans = 0;
            Node* curr = root;
            for(int i = 31; i>=0; i--)
            {
                int bit = ((x>>i)&1)?0:1;
                
                if(curr->next[bit])
                {
                    ans = ans<<1;
                    ans = ans|1;
                    // cout<<"curr: "<<bit<<", ";
                    curr = curr->next[bit];
                }
                else
                {
                    ans <<= 1;
                    ans |= 0;
                    // cout<<"curr: "<<bit<<", ";
                    curr = curr->next[1^bit];
                }
                // cout<<"i: "<<i<<", bit: "<<bit<<", ans: "<<ans<<endl;
            }
            fans = max(fans, ans);
        }
        return fans;
    }
};