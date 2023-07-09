// Clarity Questions:
// What's the limit on s.length ?
// Is there any condition on what type of characters are in use?

// Intuition:
// Let's maintain a window in this array that contains at most k distinct characters
// This window will keep on expanding to it's right and when necessary - shrink in from the left side
// We will keep expanding and keep including new elements into the array record its length update the max length encountered till now
// And when the number of distinct numbers crosses the limit k, we will start shrinking the window from the left till the number of distinct numbers is less than equal to k again

// Approach:
// We will keep 2 pointers pointing at the 2 ends of the window 
// Maintain an unordered_map 'freq' that stores the count of each character in the window
// Subsequently maintaining the count of distinct elements
// We will keep on iterating on the string and keep including the ith character as we go through the string
// As soon as we hit the limit on number of distinct elements we will start incrementing the st variable and keep excluding the characters from the left side
// And at the end of it we will return the maximum window size that satisfies the conditions above.

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> freq;
        int n = s.size();

        int st = 0, en = 0, maxLen = 0;
        while(en < n) {
            freq[s[en++]] ++;
            
            while(freq.size() > k) {
                freq[s[st]] --;
                if(freq[s[st]] == 0) {
                    freq.erase(s[st]);
                }
                st ++;
            }
            
            maxLen = max(maxLen, en - st);
        }

        return maxLen;
    }
};

// Accepted after about 25 minutes into the question

// Time Complexity => O(s.length)
// Space Complexity => O(k)