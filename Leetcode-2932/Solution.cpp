// Clarity Questions:
// What's the limit on k?
// What's the limit on rowConditions.length and colConditions.length?

class Compare {
public:
    bool operator()(vector<int> below, vector<int> above) {
        return above[0] > below[0];
    }
};

// Intuition:
// In this problem we are given 'k' number of elements that is 1 through k
// along with the relative order between some of the elements
// the order is given in two formats that is row-wise and column-wise which we need to maintain in the resultant matrix
// If we assume these k elements to be a part of two graphs:-
// rowAdj & colAdj where rowConditions contains the directed edges {u, v} such that there is an edge from u to v for the graph rowAdj and colConditions contains the same for colAdj
// Then this problem can be seen as a topological sorting problem

// Working of this Algorithm:
// First we create the graphs rowAdj and colAdj based on rowConditions and colConditions respectivly
// After that we check for cycles in both the graphs
// If there exists any cycle in any of the newly obtained graphs, we will return an empty 2D matrix because topoSort is not possible in that case
// after we have obtained the topological sort for both the graphs, we record the appropriate positions of these elements in the vector rowOrder for rowAdj and colOrder for colAdj
// Now that we have the positions for these elements in the matrix we can easily construct the matrix.

class Solution {

    bool isCyclic(vector<int>* adj, int cur, vector<bool>& dfsvis, vector<bool>& vis) {
        if(dfsvis[cur]) {
            return true;
        }

        if(vis[cur]) {
            return false;
        }
        vis[cur] = true;

        bool cyclic = false;
        dfsvis[cur] = true;
        for(int x: adj[cur]) {
            cyclic |= isCyclic(adj, x, dfsvis, vis);
        }
        dfsvis[cur] = false;

        return cyclic;
    }

    void topoSort(stack<int>& sortedElements, vector<int>* adj, int curr, vector<bool>& vis) {
        if(vis[curr]) {
            return;
        }
        vis[curr] = true;

        for(int x: adj[curr]) {
            topoSort(sortedElements, adj, x, vis);
        }
        sortedElements.push(curr + 1);
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> temp;


        vector<int> rowAdj[k];
        vector<int> rowOutDegree(k, 0);
        priority_queue<vector<int>, vector<vector<int>>, Compare> rowPQ;
        vector<bool> row1Vis(k, false);
        vector<bool> row1DfsVis(k, false);
        for(auto x: rowConditions) {
            rowAdj[x[0] - 1].push_back(x[1] - 1);
            rowOutDegree[x[0] - 1]++;
            rowOutDegree[x[1] - 1]--;
        }

        for(int i = 0; i < k; i++) {
            if(isCyclic(rowAdj, i, row1DfsVis, row1Vis)) {
                return temp;
            }
        }

        for(int i = 0; i < k; i++) {
            rowPQ.push({rowOutDegree[i], i});
        }

        vector<int> colAdj[k];
        vector<int> colOutDegree(k, 0);
        priority_queue<vector<int>, vector<vector<int>>, Compare> colPQ;
        vector<bool> col1Vis(k, false);
        vector<bool> col1DfsVis(k, false);
        for(auto x: colConditions) {
            colAdj[x[0] - 1].push_back(x[1] - 1);
            colOutDegree[x[0] - 1]++;
            colOutDegree[x[1] - 1]--;
        }

        for(int i = 0; i < k; i++) {
            if(isCyclic(colAdj, i, col1DfsVis, col1Vis)) {
                return temp;
            }
        }

        for(int i = 0; i < k; i++) {
            colPQ.push({colOutDegree[i], i});
        }

        stack<int> rowSortedElements;
        vector<bool> rowVis(k, false);
        stack<int> colSortedElements;
        vector<bool> colVis(k, false);

        while(!rowPQ.empty()) {
            int node1 = rowPQ.top()[1];
            rowPQ.pop();
            if(!rowVis[node1]) {
                topoSort(rowSortedElements, rowAdj, node1, rowVis);
            }
            int node2 = colPQ.top()[1];
            colPQ.pop();
            if(!colVis[node2]) {
                topoSort(colSortedElements, colAdj, node2, colVis);
            }
        }

        vector<int> rowOrder(k+1);
        vector<int> colOrder(k+1);
        while(!rowSortedElements.empty()) {
            rowOrder[rowSortedElements.top()] = k - rowSortedElements.size();
            rowSortedElements.pop();
            colOrder[colSortedElements.top()] = k - colSortedElements.size();
            colSortedElements.pop();
        }
        
        vector<vector<int>> ans(k, vector<int>(k, 0));

        for(int i = 1; i <= k; i++) {
            ans[rowOrder[i]][colOrder[i]] = i;
        }

        return ans;
    }
};

// Accepted after an hour into the question

// Time Complexity => O(rowConditions.length + colConditions.length + k)
// Space Complexity => O(k * k)