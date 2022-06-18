class Node {
public:
    int data;
    vector<Node*> next;
    Node(int c = -1)
    {
        data = c;
        next.resize(27,NULL);
    }
};

class Trie {
public:
    Node* root;
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(string &s, int ind)
    {
        Node* curr = root;
        for(auto c: s)
        {
            if(curr->next[c-'a'] == NULL)
                curr->next[c-'a'] = new Node(ind);
            else
                curr->next[c-'a']->data = ind;
            
            curr=curr->next[c-'a'];
        }
    }
    
    int find(string &s)
    {
        Node* curr = root;
        for(auto c: s)
        {
            if(curr->next[c-'a'] == NULL)
            {
                return -1;
            }
            curr=curr->next[c-'a'];
        }
        return curr->data;
    }
};

class WordFilter {
public:
    Trie* trie;
    WordFilter(vector<string>& words) {
        trie = new Trie();
        
        for(int i = 0 ; i < words.size(); i++)
        {
            string word = words[i];
            string s = "{"+word;
            trie->insert(s,i);
            for(int j = word.size()-1; j>=0; j--)
            {
                s = word[j] + s;
                trie->insert(s,i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = suffix+"{"+prefix;
        return trie->find(s);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */