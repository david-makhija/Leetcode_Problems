// Clarity Questions -
// Are there only 2 characters in the string? (Just to confirm)
// What is the max length of strings?
// Is there any limit on the number index-wise unequal elements in both the strings? (elements in different strings with same index but different values)
// Is there any relation between number of Xs and number of Ys?

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        // Explanation - 
        // I have seen a pattern that is - for any i, j where 0 <= i < j < n and s1[i] != s2[i] and s1[i] == s1[j] and s2[i] == s2[j] then it would require only 1 swap to make them even
        // else if the pattern is s1[i] != s2[i] and s1[i] != s1[j] and s2[i] != s2[j] then it would require 2 operations to make them even
        
        int xyPatterns = 0, yxPatterns = 0;   // So we will try to find first pattern with the help of the variables xyPatterns and yxPatterns 
        for(int i = 0; i < n; i ++) {
            // xyPatterns stores the count of induices i such that s1[i] == 'x' and s2[i] == 'y' and vica versa for yxPatterns
            if(s1[i] == 'x' and s2[i] == 'y') {
                xyPatterns ++;
            }
            else if(s1[i] == 'y' and s2[i] == 'x') {
                yxPatterns ++;
            }
        }

        // Then we will try to make pairs of patterns that are similar. (xyPatterns/2) pairs require (xyPatterns/2) number of swaps and same goes for the yxPatterns

        // So if after making these pairs one each of both the patterns is left then we will pair them together resulting in the 2nd type of pair and it will require 2 number of swaps
        // else if only one out of the two patterns is left then no Number of swaps can make the strings equal.

        return ((xyPatterns % 2) == (yxPatterns % 2)) ? ((xyPatterns / 2) + (yxPatterns / 2)) + ((xyPatterns % 2) + (yxPatterns % 2)) : -1;
    }
};

// #1 -> TLE (after 35 minutes into the question)
// #2 -> WA (after another 2 minutes into the question) test case -> s1 = xx, s2 = xy
// #3 -> WA (after another 20 minutes) test case -> s1 = xxyyxyxyxx, s2 = xyyxyxxxyx
// #4 -> Accepted (after another 22 minutes)

// Time Complexity = O(length of string);
// Space Complexity = O(1);

// Fill me up on what could I could have written in "proof of correctness" and "how will you test your code?".