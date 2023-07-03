// Clarity Questions:
// What's the limit on nums.length?

class Solution {
    int dfs(int cur, vector<int>& vis, vector<int>& nums) {
        if(vis[cur]) {
            return 0;
        }

        vis[cur] = true;
        return dfs(nums[cur], vis, nums) + 1;
    }

    // Intuition :
    // If we consider the elements of this array to be the nodes of a linked list
    // where nums[i] points to nums[nums[i]] then this array is a set of linked list cycles
    // Now we just have to calculate which cycle is the longest and avoid visiting the visited cycles.
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, false);

        int maxCycle = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                maxCycle = max(maxCycle, dfs(i, vis, nums));
            }
        }

        return maxCycle;
    }
};

// Accepted in 1 Go (took 15 minutes)

// Time Complexity => O(n)
// Space Complexity => O(n)