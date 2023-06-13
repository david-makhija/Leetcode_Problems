class Solution {
    int calculateHeight(int currNode, vector<int>* adj, vector<bool>& vis) {
        vis[currNode] = true;
        int maxH = 0;
        for(int x:adj[currNode]) {
            if(!vis[x]) maxH = max(maxH, calculateHeight(x, adj, vis));
        }
        return maxH+1;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0; i<n-1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> heights(n);
        int minH = INT_MAX;
        for(int i=0; i<n; i++) {
            vector<bool> vis(n, false);
            heights[i] = calculateHeight(i, adj, vis);
            minH = min(minH, heights[i]);
        }
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(heights[i]==minH) ans.push_back(i);
        }
        return ans;
    }
};