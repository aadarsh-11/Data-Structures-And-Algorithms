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
    vector<vector<TreeNode*>> dp;
    vector<TreeNode*> generateTrees(int n) {
        return rec(1,n);
    }
    
    vector< TreeNode* > rec(int start , int end)
    {
        if(start > end) return {NULL};
        if(start == end) return {new TreeNode(start)};
        vector<TreeNode*> ans;
        for(int i = start; i<= end; i++)
        {
            vector<TreeNode*> left = rec(start, i-1),right = rec(i+1, end);
            for(auto l: left)
            {
                for(auto r: right)
                {
                    ans.push_back(new TreeNode(i,l,r));
                }
            }
        }
        return ans;
    }
};