class SnapshotArray {
    int snap_id = 0;
    unordered_map<int, unordered_map<int, int>> snapshots;
    vector<int> changed;
    int n;
public:
    SnapshotArray(int length) {
        n = length;
        for(int i=0; i<length; i++) {
            changed.push_back(-1);
        }
    }
    
    void set(int index, int val) {
        changed[index] = val;
    }
    
    int snap() {
        unordered_map<int, int> temp;
        for(int i=0; i<n; i++) {
            if(changed[i]!=-1) {
                temp[i] = changed[i];
                changed[i] = -1;
            }
        }
        snapshots[this->snap_id] = temp;
        return this->snap_id++;
    }
    
    int get(int index, int snap_id) {
        int lo=0, hi=snap_id+1;
        while(lo<hi) {
            int mid = lo + ((hi-lo)/2);
            if(snapshots[mid].find(index)!=snapshots[mid].end()) lo = mid+1;
            else hi = mid;
        }
        return (lo>0) ? snapshots[lo-1][index] : 0;
    }
};