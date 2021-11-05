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
    int sumNumbers(TreeNode* root, int n = 0) {
        if(!root) return 0;
        if(!root->left and !root->right)
        {
            return n*10 + root->val;
        }
        int ans = 0;
        n = n*10+root->val;
        ans += sumNumbers(root->left, n);
        ans += sumNumbers(root->right, n);
        return ans;
    }
};