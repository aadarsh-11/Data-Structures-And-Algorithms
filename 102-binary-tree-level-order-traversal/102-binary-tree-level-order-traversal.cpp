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
    vector<vector<int>> lot;
    
    void rec(TreeNode* root, int h)
    {
        if(!root) return;
        if(lot.size() == h)
            lot.push_back({root->val});
        else
            lot[h].push_back(root->val);
        rec(root->left, h+1);
        rec(root->right, h+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root, int h = 0) {
        rec(root, 0);
        return lot;
    }
};