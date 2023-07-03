// Clarity Questions:
// What's the limit on n?

class Solution {

    // Intuition :
    // When we remove an element with a specific index i the aggregate sum of even indices that are greater than i changes to the aggregate sum of odd indices that are greater than i.

    bool canBeRemoved(int idx, vector<int>& oddAfterSum, vector<int>& evenAfterSum, vector<int>& nums) {
        int newEvenSum = evenAfterSum[0] - evenAfterSum[idx] + oddAfterSum[idx];
        int newOddSum = oddAfterSum[0] - oddAfterSum[idx] + evenAfterSum[idx];
        if(idx % 2 == 0) {
            newOddSum = newOddSum - nums[idx];
        }
        else {
            newEvenSum = newEvenSum - nums[idx];
        }
        return newEvenSum == newOddSum;
    }

public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        // evenAfterSum[i] stores the sum of even indices greater than or equal to i
        vector<int> evenAfterSum(n);
        // oddAfterSum[i] stores the sum of odd indices greater than or equal to i
        vector<int> oddAfterSum(n);
        
        
        if((n - 1) % 2 == 0) {
            evenAfterSum[n - 1] = nums[n - 1];
            oddAfterSum[n - 1] = 0;
        }
        else {
            oddAfterSum[n - 1] = nums[n - 1];
            evenAfterSum[n - 1] = 0;
        }

        for(int i = n - 2; i >= 0; i--) {
            if(i % 2 == 0) {
                evenAfterSum[i] = evenAfterSum[i+1] + nums[i];
                oddAfterSum[i] = oddAfterSum[i+1];
            }
            else {
                oddAfterSum[i] = oddAfterSum[i+1] + nums[i];
                evenAfterSum[i] = evenAfterSum[i+1];
            }
        }

        // ans is the variable that stores the number of indices that can be removed
        int ans = 0;

        for(int i = 0; i < n; i++) {
            // canBeRemoved function returns if the sum of even indexed elements equals to the sum of odd indexed elements after removing nums[i]
            if(canBeRemoved(i, oddAfterSum, evenAfterSum, nums)) {
                ans++;
            }
        }
        return ans;
    }
};

// Accepted in 1 Go (took 30 minutes)

// Time Complexity = O(n)
// Space Complexity = O(n)