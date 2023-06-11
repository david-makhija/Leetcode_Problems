class SnapshotArray {
    vector<int> arr;
    vector<vector<int>> snapshots;
public:
    SnapshotArray(int length) {
        for(int i=0; i<length; i++) {
            arr.push_back(0);
        }
    }
    
    void set(int index, int val) {
        arr[index] = val;
    }
    
    int snap() {
        vector<int> temp = arr;
        snapshots.push_back(temp);
        return snapshots.size()-1;
    }
    
    int get(int index, int snap_id) {
        return snapshots[snap_id][index];
    }
};