class Solution {
    int elementsTraversed = 0;
    bool isLinear = false;
    void topoSort(int idx, vector<int>* adj, vector<bool>& vis, stack<int>& st) {
        if(vis[idx]) return;
        vis[idx] = true;
        for(int x:adj[idx]) {
            topoSort(x, adj, vis, st);
        }
        st.push(idx);
    }
    bool cycleCheck(int idx, vector<int>* adj, vector<bool>& vis, vector<bool>& dfsvis, int n) {
        if(dfsvis[idx]) return true;
        if(vis[idx]) return false;
        elementsTraversed++;
        vis[idx] = true;
        dfsvis[idx] = true;
        for(int x:adj[idx]) {
            if(cycleCheck(x, adj, vis, dfsvis, n)) return true;
        }
        if(elementsTraversed==n) isLinear = true;
        elementsTraversed--;
        dfsvis[idx] = false;
        return false;
    }
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> adj[n+1];
        int m = sequences.size();
        for(int i=0; i<m; i++) {
            int l = sequences[i].size();
            int prev = 0;
            for(int j=0; j<l; j++) {
                if(prev>0) adj[prev].push_back(sequences[i][j]);
                prev = sequences[i][j];
            }
        }
        // for(int i=1; i<=n; i++) {
        //     cout<<i<<" -> ";
        //     for(int x:adj[i]) cout<<x<<" ";
        //     cout<<endl;
        // }
        stack<int> st;
        vector<bool> vis(n+1, false);
        vector<bool> dfsvis(n+1, false);
        for(int i=1; i<=n; i++) {
            if(!vis[i]) topoSort(i, adj, vis, st);
        }
        for(int i=1; i<=n; i++) {
            vis[i] = false;
        }
        if(cycleCheck(st.top(), adj, vis, dfsvis, n)) return false;
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                return false;
            }
        }
        return isLinear;
    }
};