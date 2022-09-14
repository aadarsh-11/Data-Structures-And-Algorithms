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
    int pseudoPalindromicPaths (TreeNode* root, int x = 0) {
        if(!root) return 0;
        x ^= (1<<root->val);
        if(!root->left and !root->right)
        {
            return __builtin_popcount(x) <= 1;
        }
        return pseudoPalindromicPaths(root->left, x)+ pseudoPalindromicPaths(root->right, x);
    }
};