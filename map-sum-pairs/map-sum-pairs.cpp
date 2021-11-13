class Node{
public:
    char node;
    vector<Node*> next;
    bool isWord = 0;
    int val = 0;
    Node(char c)
    {
        this->node = c;
        this->next.resize(26,NULL);
    }
};

class MapSum {
public:
    Node* root;
    map<string,int> vis;
    MapSum() {
        this->root = new Node('\0');
    }
    
    void insert(string key, int val) {
        int temp = val;
        if(vis[key])
        {
            val = val - vis[key];
        }
        vis[key] = temp;
        
        int n = key.size();
        Node* curr = root;
        for(int i = 0 ; i< n ; i++)
        {
            int ind = key[i]-'a';
            if(curr->next[ind] == NULL)
            {
                curr->next[ind] = new Node(key[i]);
            }
            
            curr = curr->next[ind];
            curr->val += val;
        }
        curr->isWord = 1;
    }
    
    int sum(string prefix) {
        int n = prefix.size();
        Node* curr = root;
        int ans = 0;
        for(int i = 0 ; i< n ; i++)
        {
            int ind = prefix[i]-'a';
            if(curr->next[ind] == NULL)
            {
                return 0;
            }
            curr = curr->next[ind];
        }
        return curr->val;
    }
};



/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */