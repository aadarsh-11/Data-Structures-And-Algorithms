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
    vector<int> io;
    void rec(TreeNode* root, int k)
    {
        if(io.size() == k) return;
        if(!root) return;
        rec(root->left, k);
        io.push_back(root->val);
        rec(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        rec(root,k);
        return io[k-1];
    }
};