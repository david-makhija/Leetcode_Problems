// Clarity Questions:
// Maximum number of vertices?
// Maximum number of edges?

// Intuition:
// It is clear in the very first glance that the question is asking us to find all those nodes that do not form a cycle in this directed graph
// I have implemented a cycle checking algorithm along with some slight modifications

// Approach:
// There are a total of 3 vectors declared in this solution:
// 1.) vis: vis[i] tells us if we have enquired for a cycle on this node or not
// 2.) dfsvis: while we perform depth first search on this graph dfsvis[i] tells us if ith node has been visited in the same path or not.
// 3.) toBeIncluded: this tells us whether to include the ith node in the answer or not i.e. if ith node is the part of a cycle then toBeIncluded[i] = false
// The role of the vector dfsvis has already been explained
// Also we have used vis and toBeIncluded to save some time
// So if the ith node has already been visited we know if it is part of a cycle or not and whether if it is a part of a cycle - this info is stored in toBeIncluded

class Solution {

    bool isCyclic(int currNode, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& dfsvis, vector<bool>& toBeIncluded) {
        if(dfsvis[currNode]) {
            return true;
        }

        if(vis[currNode]) {
            return !toBeIncluded[currNode];
        }

        vis[currNode] = true;

        dfsvis[currNode] = true;
        bool cyclic = false;
        for(int neighbour: graph[currNode]) {
            if(isCyclic(neighbour, graph, vis, dfsvis, toBeIncluded)) {
                cyclic = true;
                toBeIncluded[currNode] = false;
            }
        }
        dfsvis[currNode] = false;

        return cyclic;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;

        int n = graph.size();
        vector<bool> vis(n, false);
        vector<bool> toBeIncluded(n, true);
        vector<bool> dfsvis(n, false);

        for(int i = 0; i < n; i++) {
            isCyclic(i, graph, vis, dfsvis, toBeIncluded);
        }

        for(int i = 0; i < n; i++) {
            if(toBeIncluded[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// Wrong Answer after 20 minutes
// Accepted after another 5 minutes

// Time Complexity => O(Edges + Vertices)
// Space Complexity => O(Vertices)