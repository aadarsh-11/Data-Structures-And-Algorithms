/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root or (!root->left and !root->right)) return root;
        if(root->left and root->right)
        {
            root->left->next = root->right;
        }
        Node* curr = root->next;
        
        while(curr and !curr->left and !curr->right) curr = curr->next;
        if(curr)
        {
            if(curr->left) curr = curr->left;
            else curr = curr->right;
            
            if(root->right) root->right->next = curr;
            else root->left->next = curr;
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};