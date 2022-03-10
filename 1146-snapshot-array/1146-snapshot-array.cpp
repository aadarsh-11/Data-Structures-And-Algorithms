class SnapshotArray {
public:
    // index -> {snap_id, val};
    vector<vector<pair<int,int>>> snaps;
    int snap_id = 0;
    
    SnapshotArray(int length) {
        snaps.resize(length);
    }
    
    void set(int index, int val) {
        if(snaps[index].size() > 0 and snaps[index].back().second == val) return;
        if(snaps[index].size() > 0 and snaps[index].back().first == snap_id)
            snaps[index].back().second = val;
        else
            snaps[index].push_back({snap_id, val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        int n = snaps[index].size();
        int l = 0, r = n-1;
        
        if(n == 0 or snaps[index][l].first > snap_id) return 0;
        
        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(snaps[index][mid].first <= snap_id)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        if(l >= n or snaps[index][l].first > snap_id) l--;
        
        return snaps[index][l].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */