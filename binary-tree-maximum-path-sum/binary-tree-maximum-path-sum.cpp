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
    int ans = INT_MIN;
    int rec(TreeNode* root)
    {
        if(!root) return 0;
        int l = rec(root->left);
        int r = rec(root->right);
        ans = max(ans, root->val+l+r);
        return max({root->val,0,(root->val + max(l,r))});
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        rec(root);
        return ans;
    }
};