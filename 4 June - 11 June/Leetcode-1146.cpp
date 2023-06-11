class SnapshotArray {
    vector<int> arr;
    int snap_id = 0;
    unordered_map<int, unordered_map<int, int>> snapshots;
    vector<int> changed;
    int n;
public:
    SnapshotArray(int length) {
        n = length;
        for(int i=0; i<length; i++) {
            arr.push_back(0);
            changed.push_back(-1);
        }
    }
    
    void set(int index, int val) {
        changed[index] = val;
        arr[index] = val;
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
        for(auto itr=snapshots.begin(); itr!=snapshots.end(); itr++) {
            if(itr->first<=snap_id and itr->second.find(index)!=itr->second.end()) return itr->second[index];
        }
        return 0;
    }
};