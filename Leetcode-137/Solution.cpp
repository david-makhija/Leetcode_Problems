// Clarity Questions :
// What's the max length of nums?

class Solution {

    // Intuition :
    // It is a pretty straight forward solution in which we are just maitaining an unordered map freq which records the frequency of each nums[i]
    // and when for a particular element it reaches 3 the element gets erased from the map
    // Thus after the loop, the only remaining element would be the one that occurs only once
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]] ++;
            if(freq[nums[i]] == 3) {
                freq.erase(nums[i]);
            }
        }
        return freq.begin() -> first;
    }
};

// Accepted after 10 minutes into the question.

// Time Complexity => O(n)
// Space Complexity => O(n)