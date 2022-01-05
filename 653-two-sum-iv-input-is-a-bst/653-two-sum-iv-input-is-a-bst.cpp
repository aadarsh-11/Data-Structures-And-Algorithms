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
    map<int,int> mp;
    bool ans = 0;
    
    void rec(TreeNode* root, int k)
    {
        if(!root) return;
        int x = root->val;
        rec(root->left,k);
        if(mp[k - x]) ans = 1;
        mp[root->val]++;
        rec(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        rec(root,k);
        return ans;
    }
};