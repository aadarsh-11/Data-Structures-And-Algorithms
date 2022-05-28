class TreeAncestor {
public:
    vector<vector<int>> up;
    vector<int> depth;
    int LOG = 0;
    
    TreeAncestor(int n, vector<int>& parent) {
        while((1<<LOG) <= n) LOG++;
        
        depth = vector<int>(n);
        up = vector<vector<int>>(n, vector<int>(LOG));
        // parent[0] = 0;
        // depth[0] = -1;
        
        for(int i = 0 ; i < n; i++)
        {
            up[i][0] = parent[i];
            // depth[i] = depth[parent[i]]+1;
        }
        
        for(int j = 1; j < LOG; j++)
        {
            for(int i = 0; i<n; i++)
            {
                if(up[i][j-1] == -1) up[i][j] = -1;
                else up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        // if(depth[node]<k) return -1;
        int x = 0;
        while(x<LOG)
        {
            if((1<<x) & k)
            {
                if(node == -1) return -1;
                node = up[node][x];
            }
            x++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */