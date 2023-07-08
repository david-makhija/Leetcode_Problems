// Clarity Questions:
// What's the maximum length of answerKey
// What's the limit on k?

// Intuition:
// At a time we will try to find the maximum length of one specific boolean value obtained via switching a maximum of k boolean values
// Then we will return maximum of both of them. Now let us look at how calculate this max length for each boolean value
// I am thinking of maintaining a window whose length would signify the length that we are trying to maximize that is - all the characters in that index limit would represent the same boolean value via switching at most k boolean values
// In each iteration we would increase the ending index of this window if the new character is the desired one then we will take no action else we would either switch it to the desired value and decrement the possible number of switches or if the possible number of switches is 0 then we will try and find the character with least index that is the part of our window and was switched and subsequently keep reducing the size of our window

// Approach:
// The Intuition pretty much summarizes the approach.


class Solution {
    int maxLength(string answerKey, int k, int n, char target) {
        int st = 0, en = 0;
        int maxLen = 0;
        
        
        while(en < n) {
            while(answerKey[en] != target and k == 0) {
                if(answerKey[st] != target) {
                    k ++;
                }
                st ++;
            }
            
            if(answerKey[en] != target) {
                k --;
            }
            
            en ++;
            maxLen = max(en - st, maxLen);
        }
        
        return maxLen;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxLength(answerKey, k, answerKey.size(), 'T'), maxLength(answerKey, k, answerKey.size(), 'F'));
    }
};

// Accepted after 30 minutes into the Question

// Time Complexity => O(n)
// Space Complexity => O(1)