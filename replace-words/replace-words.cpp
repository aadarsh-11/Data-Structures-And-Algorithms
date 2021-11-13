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
    
    string startsWith(string s) {
        int n = s.size();
        Node* curr = root;
        string ans = "";
        for(int i = 0; i<n; i++)
        {
            if(curr->next[s[i]-'a'] == NULL) return "";
            if(curr->next[s[i]-'a']->isWord)
            {
                ans += curr->next[s[i]-'a']->node;
                return ans;
            }
            curr = curr->next[s[i]-'a'];
            ans += curr->node;
        }
        return "";
    }
    
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        Trie* tree = new Trie();
        for(auto i: dict)
        {
            tree->insert(i);
        }
        string wd = "";
        int n = s.size();
        string ans = "";
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == ' ')
            {
                string x = tree->startsWith(wd);
                cout<<x;
                if(x != "")
                {
                    wd = x;
                }
                if(ans != "") ans += " ";
                ans += wd;
                wd = "";
            }
            else
            {
                wd+=s[i];
            }
        }
        string x = tree->startsWith(wd);
        cout<<x;
        if(x != "")
        {
            wd = x;
        }
        if(ans != "") ans += " ";
        ans += wd;
        return ans;
    }
};