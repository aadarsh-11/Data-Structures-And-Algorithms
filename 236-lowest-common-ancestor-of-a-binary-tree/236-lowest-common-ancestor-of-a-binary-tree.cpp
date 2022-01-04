/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool found = 0;
    TreeNode* ans;
    
    int rec(TreeNode* root, TreeNode* a, TreeNode* b)
    {
        if(!root) return 0;
        int l = rec(root->left,a,b);
        int r = rec(root->right,a,b);
        if((l+r) == 2 and !found)
        {
            ans = root;
            found = 1;
            return 2;
        }
        if((l+r) == 2) return 2;
        
        if(root == a or root == b)
        {
            if((l+r) == 1)
            {
                ans = root;
                found = 1;
                return 2;
            }
            else
            {
                return 1;
            }
        }
        return (l+r);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rec(root,p,q);
        return ans;
    }
};