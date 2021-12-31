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
    int ans = 0;
    pair<int,int> rec(TreeNode* root)
    {
        if(!root) return {-1,-1};
        pair<int,int> x = {-1,-1};
        int mx = root->val,mn=root->val;
        pair<int,int> mm,mmm;
        mm = rec(root->left);
        if(mm != x)
        {
            ans = max({ans, abs(root->val-mm.first), abs(root->val-mm.second)});
            mx = max({root->val,mm.first, mm.second});
            mn = min({root->val,mm.first, mm.second});
        }
        
        mmm = rec(root->right);
        if(mmm != x)
        {
            ans = max({ans, abs(root->val-mmm.first), abs(root->val-mmm.second)});
            mx = max({mx,mmm.first, mmm.second});
            mn = min({mn,mmm.first, mmm.second});
        }
        return {mx,mn};
    }
    int maxAncestorDiff(TreeNode* root) {
        rec(root);
        return ans;
    }
};