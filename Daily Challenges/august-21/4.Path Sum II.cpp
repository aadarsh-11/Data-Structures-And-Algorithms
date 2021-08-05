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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }
    void dfs(TreeNode* root, int ts, vector<int>& path)
    {
        if(root == nullptr) return;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            if(ts == root->val)
            {
                ans.push_back(path);
            }
        }
        else
        {
            ts -= root->val;
            dfs(root->left, ts, path);
            dfs(root->right, ts, path);
        }
        path.pop_back();
        
    }
};
