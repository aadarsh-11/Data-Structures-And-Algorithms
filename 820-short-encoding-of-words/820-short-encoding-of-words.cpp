class Node {
public:
    vector<Node*> next;
    Node()
    {
        next.resize(26, NULL);
    }
};

class Trie {
public:
    Node* root = new Node();
    
    int insert(string &s)
    {
        bool ret = 0;
        Node* curr = root;
        for(auto c: s)
        {
            int i = c-'a';
            if(curr->next[i] == NULL)
            {
                curr->next[i] = new Node();
                ret = 1;
            }
            curr = curr->next[i];
        }
        return (ret ? s.size() + 1: 0);
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string &s1,string &s2) {
            return s1.size() > s2.size();
        });
        
        Trie t;
        int ans = 0;
        for(auto &s: words)
        {
            reverse(s.begin(), s.end());
            ans += t.insert(s);
        }
        return ans;
    }
};