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
    vector<int> prefix;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        prefix.push_back(root->val);
        root->val = prefix.size()-1;
        inorder(root->right);
    }
    
    void helper(TreeNode* root)
    {
        if(!root) return;
        
        helper(root->left);
        root->val = prefix[root->val];
        helper(root->right);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        for(int i = prefix.size()-2; i>=0; i--)
        {
            prefix[i] += prefix[i+1];
        }
        helper(root);
        return root;
    }
};