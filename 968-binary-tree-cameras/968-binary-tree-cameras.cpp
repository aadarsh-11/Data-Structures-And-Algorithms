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
    int noc = 0, hasc = 1, notn = 2, ans = 0;
    
    int dfs(TreeNode* root)
    {
        if(!root) return notn;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if(l == noc or r == noc)
        {
            ans++;
            return hasc;
        }
        if(l == hasc or r == hasc)
            return notn;
        return noc;
    }
    
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == noc) ans++;
        return ans;
    }
};