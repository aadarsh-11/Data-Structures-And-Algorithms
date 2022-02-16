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
    map<int, vector<TreeNode*>>dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.find(n) != dp.end()) return dp[n];
        vector<TreeNode*> v;
        if(n == 0 or n == 2)
        {
            return v;
        }
        if(n == 1)
        {
            TreeNode* root = new TreeNode();
            v.push_back(root);
            return v;
        }
        if(n == 3)
        {
            TreeNode* l = new TreeNode();            
            TreeNode* r = new TreeNode();
            TreeNode* root = new TreeNode(0,l,r);
        }
        
        for(int i = 0; i<=n/2; i++)
        {
            vector<TreeNode*> lst = allPossibleFBT(i);
            vector<TreeNode*> rst = lst;
            if(i != n-i-1)
                rst = allPossibleFBT(n-i-1);
                
            for(auto l:  lst)
            {
                for(auto r: rst)
                {
                    TreeNode* root = new TreeNode(0,l,r);
                    v.push_back(root);
                    
                    if(i != n-i-1)
                    {
                        root = new TreeNode(0,r,l);
                        v.push_back(root);                        
                    }
                }
            }
        }
        return dp[n] = v;
    }
};