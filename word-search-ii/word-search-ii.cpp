class node{
    
    public:
    char c;
    int wordend;
    vector<node*> children;
    
    node(char C = ' '){
        this->c = C;
        this->wordend=0;
        children.resize(26,NULL);
    }
    
    
};

class Trie{
    
    public:
    node* Root;
    
    Trie() {Root = new node();}
    
    void insert(string& word){
        int n = word.length();
        int i = 0;
        
        node* curr = this->Root;
        
        while(i < n){
            char c = word[i];
            
            if(curr->children[c-'a']==NULL)
                curr->children[c-'a'] = new node(c);
            
            curr = curr->children[c-'a'];   
            
            i++;
        }
        
        curr->wordend++;
        return; 
    }
    
    
    
    
};


class Solution {
public:
    Trie* trie;
    unordered_set<string> found; 
    
    int R; int C; vector<vector<char>> mat;
    vector<int> x {0,0,1,-1};
    vector<int> y {-1,1,0,0};
    
    
    void dfsWithTrie(int i, int j, node* curr, string s){
        
        char c = mat[i][j];
        
        if(curr->children[c-'a']==NULL) return;
        
        char replace = mat[i][j];
        
        mat[i][j] = '-';
        
        s += c;
        
        if(curr->children[c-'a']->wordend > 0) found.insert(s);
        
        for(int d=0 ; d<4;d++){
            int newI = i+ x[d];
            int newJ = j + y[d];
            if(isValid(newI,newJ))
                dfsWithTrie(newI, newJ, curr->children[c-'a'], s);
        }
        
        mat[i][j] = replace;
        
        return; 
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->trie = new Trie;
        
        for(string& s : words)
            trie->insert(s);
        
        this->R = board.size();
        this->C = board[0].size();
        this->mat = board;
        
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                dfsWithTrie(i,j,trie->Root,"");
        
        
        vector<string> ans;
        for(string s : found)
            ans.push_back(s);
        
        return ans;
        
    }
    
    bool isValid(int i, int j){
        
        if(i > -1 && i < R && j > -1 && j < C && mat[i][j] != '-')
            return true;
        else return false; 
        
    }
};