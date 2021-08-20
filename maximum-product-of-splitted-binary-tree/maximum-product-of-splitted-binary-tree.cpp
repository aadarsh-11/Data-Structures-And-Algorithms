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
    int rs = -1;
    int sumtree(TreeNode* root)
    {
        if(root->left)
        {
            root->val += sumtree(root->left);
        }
        if(root->right)
        {
            root->val += sumtree(root->right);
        }
        return root->val;
    }
    long long int maxp(TreeNode* root)
    {
        long long int ans = (long long int)(rs-root->val) * (long long int)root->val;
        if(root->left)
        {
            ans = max(ans, maxp(root->left));
        }
        if(root->right)
        {
            ans = max(ans, maxp(root->right));
        }
        return ans;
    }
    int maxProduct(TreeNode* root) {
        
        rs = sumtree(root);
        int mod = 1e9+7;
        return (int)(maxp(root)%(mod));
    }
};