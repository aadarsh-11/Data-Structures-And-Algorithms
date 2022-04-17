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
    TreeNode* curr = new TreeNode();
    TreeNode* ans = curr;
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        
        TreeNode* l = increasingBST(root->left);
        curr->right = new TreeNode(root->val);
        curr = curr->right;
        TreeNode* r = increasingBST(root->right);
        return ans->right;
    }
};