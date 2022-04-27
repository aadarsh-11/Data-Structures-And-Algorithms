class unionFind {
    int n = 0;
    vector<int> group,rank;
    public:
    unionFind(int n)
    {
        group.resize(n,0);
        rank.resize(n,0);
        for(int i = 0 ; i < n; i++)
        {
            group[i] = i;
        }
    }
    
    int Union(int x, int y)
    {
        int g1 = Find(x);
        int g2 = Find(y);
        
        if(g1 == g2) return 0;
        
        if(rank[g1] == rank[g2])
        {
            group[g2] = g1;
            rank[g1]++;
        }
        else if(rank[g1] > rank[g2])
        {
            group[g2] = g1;
        }
        else
        {
            group[g1] = g2;
        }
        return 1;
    }
    
    int Find(int x)
    {
        if(group[x] != x) return group[x] = Find(group[x]);
        return group[x];
    }    
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        unionFind uf(n);
        for(auto v: pairs)
        {
            uf.Union(v[0],v[1]);
        }
        map<int,string> mp;
        map<int,int> ind;
        
        for(int i = 0 ; i < n ; i++)
        {
            int g = uf.Find(i);
            mp[g] += s[i];
        }
        for(auto &i: mp)
        {
            sort(i.second.begin(),i.second.end());
        }
        string ans(n,'*');
        for(int i = 0 ; i < n ; i++)
        {
            ans[i] = mp[uf.Find(i)][ind[uf.Find(i)]++];
        }
        return ans;
    }
};