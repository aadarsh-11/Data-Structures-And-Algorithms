/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#define pb push_back

class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return ans;
        vector<int> x;
        Node * croot = root;
        vector<Node * > cr;
        vector<Node * > ch;
        cr.pb(root);
        // int n = 1;
        while(cr.size() > 0)
        {            
            for(auto i: cr)
            {
                x.pb(i->val);
                for(auto j: i->children)
                {
                    ch.pb(j);
                }
            }
            ans.pb(x);
            x.clear();
            cr.clear();
            cr = ch;
            ch.clear();
        }
        return ans;
    }
};