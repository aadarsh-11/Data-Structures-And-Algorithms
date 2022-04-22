class MyHashMap {
public:
    vector<list<pair<int,int>>> hm;
    int m_size = 100;
    
    MyHashMap() {
        hm.resize(m_size);
    }
    
    void put(int key, int value) {
        int ind = key%m_size;
        auto &l = hm[ind];
        
        for(auto &i : l)
        {
            if(i.first == key)
            {
                i.second = value;
                return;
            }
        }
        
        l.push_back({key,value});
    }
    
    int get(int key) {
        int ind = key%m_size;
        auto &l = hm[ind];
        // if(l.empty()) return -1;
        for(auto &i:l)
        {
            if(i.first == key) return i.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int ind = key%m_size;
        auto &l = hm[ind];
        l.remove_if([key](auto n) { return n.first == key; });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */