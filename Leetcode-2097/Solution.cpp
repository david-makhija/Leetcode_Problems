// Clarity Questions :
// What's the maximum value of pairs[i][0] and pairs[i][1] where 0 <= i < pairs.length ?
// what's the limit on pairs.length ?

class Solution {
    vector<vector<int>> ans;

    void euler(unordered_map<int, stack<int>>& adj, int cur) {
        auto& stk = adj[cur];
        while(!stk.empty()) {
            int nei = stk.top();
            stk.pop();
            euler(adj, nei);
            ans.push_back({cur, nei});
        }
    }

    // Intuition:
    // Suppose that the elements start_i and end_i are nodes in a directed graph
    // and pairs[i] is a directed edge from start_i and end_i
    // Then it becomes clear - all we have to find is a eulerian path in this graph
    // i.e. a path that covers all of the edges exactly once

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, stack<int>> adj;
        unordered_map<int, int> outDegree;
        unordered_map<int, int> inDegree;
        int m = pairs.size();
        adj.reserve(m);
        inDegree.reserve(m);
        outDegree.reserve(m);
        for(int i = 0; i < m; i++) {
            adj[pairs[i][0]].push(pairs[i][1]);
            outDegree[pairs[i][0]]++;
            inDegree[pairs[i][1]]++;
        }

        for(auto itr = adj.begin(); itr != adj.end(); itr++) {
            if(outDegree[itr->first] > inDegree[itr->first]) {
                euler(adj, itr->first);
                break;
            }
        }
        
        
        if(ans.empty()) {
            euler(adj, pairs[0][0]);
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Not Accepted even after 1 day into the question :"(
// Had to read the editorial :/

// Time Complexity => O(pairs.length)
// Space Complexity => O(pairs.length)