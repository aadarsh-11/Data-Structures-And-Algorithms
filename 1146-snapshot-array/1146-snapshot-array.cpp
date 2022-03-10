class SnapshotArray {
public:
    // index -> {snap_id, val};
    vector<vector<pair<int,int>>> snaps;
    int snap_id = 0;
    
    SnapshotArray(int length) {
        snaps.resize(length);
    }
    
    void set(int index, int val) {
        if(snaps[index].empty() || snaps[index].back().first < snap_id)
            snaps[index].push_back({snap_id, val});
        else
            snaps[index].back().second = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        int n = snaps[index].size();
        int l = 0, r = n-1;
        
        auto it = upper_bound(snaps[index].begin(), snaps[index].end(), make_pair(snap_id,INT_MAX));
        
        if(it == snaps[index].begin()) return 0;
        
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */