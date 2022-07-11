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
    void rec(TreeNode* root, vector<int>& v, int lvl)
    {
        if(!root) return;
        if(v.size() == lvl)
        {
            v.push_back(root->val);
        }
        rec(root->right, v, lvl+1);
        rec(root->left, v, lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rec(root, ans, 0);
        return ans;
    }
};