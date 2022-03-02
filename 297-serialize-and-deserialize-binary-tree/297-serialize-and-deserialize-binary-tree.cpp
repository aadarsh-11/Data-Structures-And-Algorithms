/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // base case;
        if(!root) return "#";
        
        // add root value;
        string ans = to_string(root->val) + ",";
        
        //call for left rec
        string left = serialize(root->left);
        int ls = left.size()+1;
        
        //add size of left substring and then add left string;
        ans += to_string(ls) + "," + left + ",";
        
        //do the same for right;
        string right = serialize(root->right);
        ans += right;

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // check for null Node
        if(data[0] == '#') return NULL;
        
        int i = 0;
        int sign = 0;
        int val = 0;
        
        // check for negetive sign
        if(data[i] == '-')
        {
            sign = 1;
            i++;
        }
        
        //calculate root val;
        while(data[i] != ',')
        {
            val = val*10 + (data[i]-'0');
            i++;
        }
        if(sign) val *= -1;
        
        //create root node
        TreeNode* root = new TreeNode(val);
        
        // currently at comma so go ahead
        i++;
        
        //size of left subtree string
        int ls = 0;
        while(data[i] != ',')
        {
            ls = ls*10 + (data[i]-'0');
            i++;
        }
        i++;
        
        //recurse for the left subtree
        root->left = deserialize(data.substr(i,ls));
        
        //go to the first index of right subtree string
        i += ls;
        
        // recurse for the right subtree
        root->right = deserialize(data.substr(i, data.size()-ls-2));
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));