/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        vector<TreeNode*> ino;
        int x = 1;
        while(!st.empty() or root)
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ino.push_back(root);
            // cout<<root->val<<" ";
            root = root->right;
        } 
        
        int n = ino.size();
        int f,s;
        for(int i = 0; i <n-1; i++)
        {
            if(ino[i]->val > ino[i+1]->val)
            {
                f = i;
                s = i+1;
                break;
            }
        }
        for(int i = s; i<n-1; i++)
        {
            if(ino[i]->val > ino[i+1]->val)
            {
                s = i+1;
                break;
            }
        }
        // cout<<f<<" "<<s<<endl;
        swap(ino[f]->val,ino[s]->val);
    }
};