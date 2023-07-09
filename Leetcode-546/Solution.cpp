// Clarity Questions:
// What's the limit on boxes.length ?

// Intuition:
// It is quite obvious to approach this problem with recursive solution because it can be further divided into solvable Subproblems
// And afterwards you can also apply dp to this to further optimize the time complexity
// But, the way you define the subproblems matters the most 
// Because here you might think that a subproblem might be defined as just a subarray
// But this is not the case - because if you do so, it might not work for larger test cases and might give TLE
// So to define a subproblem we would consider 3 variables -
// 1.) Starting index of the subarray
// 2.) Ending index of the subarray
// 3.) Number of elements trailing the last element that have the same value as last element
// Now one can clearly see that the recurrence relation would be -
// dp[st][en][trailingElements] = dp[st][en - 1][0] + (trailingElements + 1) * (trailingElements + 1)
// where boxes[en - 1] != boxes[en] and st < en
// but here we forgot to take into consideration the elements that have the same value as last element but are in the range [st: en - 1]
// Now the new relation would be -
// dp[st][en][trailingElements] = max(dp[st][i][trailingElements + 1] + dp[i + 1][en - 1][0], dp[st][en][trailingElements])
// for every i in between st and en - 1 where boxes[en - 1] != boxes[en] and boxes[i] == boxes[en]

class Solution {

    int pointsCalculator(vector<int>& boxes, int st, int en, int trailingElements, vector<vector<vector<int>>>& dp) {
        if(st > en) {
            return 0;
        }

        while(en > st and boxes[en] == boxes[en - 1]) {
            en --;
            trailingElements ++;
        }

        if(dp[st][en][trailingElements] != -1) {
            return dp[st][en][trailingElements];
        }

        dp[st][en][trailingElements] = pointsCalculator(boxes, st, en - 1, 0, dp) + (trailingElements + 1) * (trailingElements + 1);

        for(int i = st; i < en; i++) {
            if(boxes[i] == boxes[en]) {
                dp[st][en][trailingElements] = max(pointsCalculator(boxes, st, i, trailingElements + 1, dp) + pointsCalculator(boxes, i + 1, en - 1, 0, dp), dp[st][en][trailingElements]);
            }
        }

        return dp[st][en][trailingElements];
    }

public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        return pointsCalculator(boxes, 0, n - 1, 0, dp);
    }
};

// Tried really hard, took a lot of time and effort but could not code it myself. At first I got Wrong Answer for many inputs but as I carved my way through sculpting the algorithm to cope with those test cases I ended up getting TLE
// Read the editorial and wrote this beautiful solution

// Time Complexity => O((boxes.length)^4)
// Space Complexity => O((boxes.length)^3)