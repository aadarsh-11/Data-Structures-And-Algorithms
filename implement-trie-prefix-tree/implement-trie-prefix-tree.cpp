class Node {
public:
    char node;
    vector<Node*> next;
    bool isWord = 0;
    Node(char c)
    {
        this->node = c;
        this->next.resize(26,NULL);
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        this->root = new Node('\0');
    }
    
    void insert(string s) {
        int n = s.size();
        Node* curr = root;
        for(int i = 0; i<n; i++)
        {
            if(curr->next[s[i]-'a'] == NULL)
            {
                curr->next[s[i]-'a'] = new Node(s[i]);
            }
            curr = curr->next[s[i]-'a'];
        }
        curr->isWord = 1;
    }
    
    bool search(string s) {
        int n = s.size();
        Node* curr = root;
        for(int i = 0; i<n; i++)
        {
            if(curr->next[s[i]-'a'] == NULL)
            {
                return 0;
            }
            curr = curr->next[s[i]-'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string s) {
        int n = s.size();
        Node* curr = root;
        for(int i = 0; i<n; i++)
        {
            if(curr->next[s[i]-'a'] == NULL)
            {
                return 0;
            }
            curr = curr->next[s[i]-'a'];
        }
        return 1;
    }
    
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */