// Clarity Questions :
// What's the limit of nums.size() ?

class Solution {

    // Intuition :
    // First this algorithm calculates the maximum or possible with this array
    // Then it tries to make all possible subsets subsequently calculating the or of this subset
    // if this 'or' is equal to maxOr then we return 1 else we return 0
    // and as soon as the recursive call is over we keep building our count.

    int calculateSubsets(int cur, vector<int>& nums, int maxOr, int currOr, int n) {
        if(cur == n) {
            return (currOr == maxOr) ? 1 : 0;
        }

        return calculateSubsets(cur + 1, nums, maxOr, currOr, n) + calculateSubsets(cur + 1, nums, maxOr, currOr | nums[cur], n);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            maxOr |= nums[i];
        }

        return calculateSubsets(0, nums, maxOr, 0, n);
    }
};

// Wrong Answer after 22 minutes into the question
// Accepted after another 10 minutes

// Time Complexity => O(nums.length)
// Space Complexity => O(1)