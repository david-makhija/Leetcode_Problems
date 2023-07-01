// Clarity Questions
// what's the limit on k?
// What's the limit on cookies.length()?

class Solution {
    int distributor(vector<int>& cookies, int idx, int maxCookies, int k, vector<int>& kids, int n) {
        if(idx == n) {
            return maxCookies;
        }

        int ans = INT_MAX;

        for(int i=0; i<k; i++) {
            kids[i] += cookies[idx];
            ans = min(ans, distributor(cookies, idx+1, max(maxCookies, kids[i]), k, kids, n));
            kids[i] -= cookies[idx];
        }

        return ans;
    }
public:
    // The approach is bruteforce because the limits anre fundamental
    // We are distrbuting the bags to each one of the kids 
    // And keeping track of the maximum cookies a kid has in each distribution
    // and out of all these maximums we will return the minimum of these.
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> kids(k, 0);
        return distributor(cookies, 0, 0, k, kids, cookies.size());
    }
};

// Accepted (12 minutes)

// Time Complexity -> O(k^cookies.length)
// Space Complexity -> O(k)