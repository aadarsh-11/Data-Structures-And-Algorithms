class Node {
    public:
    char node;
    vector<Node*> next;
    bool isWord = false;
    Node(char c)
    {
        this->node = c;
        this->next.resize(26,NULL);
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        this->root = new Node('\0');
        
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i = 0 ; i < word.size(); i++)
        {            
            if(curr->next[word[i]-'a'] == NULL)
            {
                curr->next[word[i]-'a'] = new Node(word[i]);
            }
            curr = curr->next[word[i]-'a'];
        }
        curr->isWord = true;
        
    }
    
    bool search(string word, Node* curr = NULL, int start = 0) {
        if(!curr) curr = root;
        for(int i = start ; i < word.size(); i++)
        {
            if(word[i] == '.')
            {
                bool ans = 0;
                for(int j = 0 ; j < 26; j++)
                {
                    if(curr->next[j])
                    {
                        ans = ans || search(word, curr->next[j], i+1);
                    }
                }
                return ans;
            }
            if(curr->next[word[i]-'a'] == NULL)
            {
                return false;
            }
            curr = curr->next[word[i]-'a'];
        }
        return curr->isWord;
        
    }
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */