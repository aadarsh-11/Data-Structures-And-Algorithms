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
    TreeNode * rec(TreeNode *root)
    {
        TreeNode* l;
        if(root->left)
        {
            l = rec(root->left);
            l->right = root->right;
            root->right = root->left;
            root->left = NULL;
            if(l->right)
            root = rec(l->right);
        }
        if(root->right)
        {
            root = rec(root->right);
        }
        return root;
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        rec(root);
    }
};