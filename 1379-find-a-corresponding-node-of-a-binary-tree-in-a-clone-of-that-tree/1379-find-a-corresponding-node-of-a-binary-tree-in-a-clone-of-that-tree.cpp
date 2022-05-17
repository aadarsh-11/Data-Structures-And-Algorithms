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
    stack<int> path;
    
    bool find(TreeNode* root, TreeNode* target)
    {
        if(!root) return 0;
        if(root == target)
        {
            return 1;
        }
        bool l = find(root->left, target);
        if(l)
        {
            path.push(0);
            return 1;
        }
        bool r = find(root->right, target);
        if(r)
        {
            path.push(1);
            return 1;
        }
        return 0;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        find(original, target);
        while(!path.empty())
        {
            int dir = path.top();
            path.pop();
            if(dir)
            {
                cloned = cloned->right;
            }
            else
            {
                cloned = cloned->left;
            }
        }
        return cloned;
    }
};