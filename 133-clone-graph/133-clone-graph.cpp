/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int, Node*> done;
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node* head = new Node(node->val);
        done[head->val] = head;
        for(auto n: node->neighbors)
        {
            if(done[n->val])
                head->neighbors.push_back(done[n->val]);
            else
                head->neighbors.push_back(cloneGraph(n));
        }
        return head;
    }
};