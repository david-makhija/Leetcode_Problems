// Clarity Questions:
// What's the limit on nums.length?

// Intuition:
// My Intuition here is to implement binary search along with prefix sum - have a look at the approach to understand it better

// Approach:
// We will make a vector named prefixSum of size n + 1 such that prefixSum[i] = sum of elements of nums from index 0 to i - 1
// This way we can easily calculate any subarray sum in O(1) time
// For example: for a subarray ranging from index j to i it would be prefixSum[i + 1] - prefixSum[j]
// Now we can iterate through the array and for prefixSum[i] we will search for a value that is just lesser than or equal to prefixSum[i] - target

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        vector<int> prefixSum(n + 1, 0);
        int k = 0;
        for(int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
            if(k == 0 and prefixSum[i] >= target) {
                k = i;
            }
        }
        if(prefixSum[n] < target) {
            return 0;
        }
        for(; k <= n; k++) {
            auto itr = upper_bound(prefixSum.begin(), prefixSum.end(), prefixSum[k] - target);
            if(itr != nums.end()) {
                int j = max((int)(itr - prefixSum.begin() - 1), 0);
                cout<<k<<" "<<j<<endl;
                minLen = min(minLen, k - j);
            }
        }
        return minLen;
    }
};