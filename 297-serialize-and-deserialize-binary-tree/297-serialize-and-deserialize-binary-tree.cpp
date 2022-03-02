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
        if(!root) return "v:#";
        
        // add root value;
        string ans = "v:" + to_string(root->val) + ",";
        
        //call for left rec
        string left = serialize(root->left);
        int ls = left.size()+1;
        //add size of left substring and then add left string;
        ans += to_string(ls) + "," + left + ",";
        
        //do the same for right;
        string right = serialize(root->right);
        int rs = right.size();
        ans += to_string(rs) + "," + right;
        // cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[2] == '#') return NULL;
        int i = 2;
        int val = 0;
        int sign = 0;
        
        if(data[i] == '-')
        {
            sign = 1;
            i++;
        }
        
        while(data[i] != ',')
        {
            val = val*10 + (data[i]-'0');
            i++;
        }
        if(sign) val *= -1;
        
        TreeNode* root = new TreeNode(val);
        i++;
        int ls = 0;
        while(data[i] != ',')
        {
            ls = ls*10 + (data[i]-'0');
            i++;
        }
        i++;
        root->left = deserialize(data.substr(i,ls));
        i += ls;
        
        
        int rs = 0;
        while(data[i] != ',')
        {
            rs = rs*10 + (data[i]-'0');
            i++;
        }
        i++;
        root->right = deserialize(data.substr(i,rs));
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));