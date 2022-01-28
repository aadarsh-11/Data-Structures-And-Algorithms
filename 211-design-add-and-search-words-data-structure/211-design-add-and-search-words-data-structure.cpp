class Node {
    public:
    bool isWord;
    vector<Node*> next;
    char val;
    Node(char c)
    {
        isWord = false;
        val = c;
        next.resize(26,NULL);
    }
};

class trie {
    public:
    Node* root;
    trie()
    {
        root = new Node('.');
    }
    
    void add(string word)
    {
        Node* curr = root;
        for(auto j: word)
        {
            int i = j-'a';
            if(!curr->next[i])
                curr->next[i] = new Node(j);
            curr = curr->next[i];
        }
        curr->isWord = true;
    }
    
    bool search(string word, int start, Node* curr)
    {
        if(!curr)
            curr = root;
        for(int i = start ; i<word.size(); i++)
        {
            if(word[i] == '.')
            {
                bool ans = 0;
                for(int j = 0 ; j < 26; j++)
                {
                    if(curr->next[j])
                    {
                        ans = ans || search(word, i+1, curr->next[j]);
                    }
                }
                return ans;
            }
            if(!curr->next[word[i]-'a'])
                return false;
            curr = curr->next[word[i]-'a'];
        }
        return curr->isWord;
    }
};

class WordDictionary {
public:
    trie* t;
    WordDictionary() {
        t = new trie();
    }
    
    void addWord(string word) {
        t->add(word);
    }
    
    bool search(string word) {
        return t->search(word,0,NULL);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */