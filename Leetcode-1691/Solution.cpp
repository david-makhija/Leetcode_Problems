// Clarity Questions :
// maximum length of cuboids vector?
// maximum possible height of stacked cuboids?

class Solution {
    // Intuition :
    // The dimensions of a cuboid can be arranged in any order so why not we take an advantage from thsi
    // and consider the maximum side as height and minimum as width and medium as length
    // After this we can sort the cuboids array in such a way that the cuboid having minimum dimensions is at first and the one with maximum dimensions at last
    // When it is sorted, it is obvious that for any i, j where 0 <= i < j < n , cuboid[i] could be placed upon cuboid[j] but cuboid[j] being placed onto cuboid[i] is not a possibility.
    // dp[j] stores the maximum height of stacked cuboids when we are provided with j+1 cuboids
    // Thus for each j where 1 <= j < n we try to place each cuboid having dimensions lesser than this cuboid and subsequently update the value of dp[j] to store the maximum value.
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        int n = cuboids.size();
        for(int i = 0; i < n; i++) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        sort(cuboids.begin(), cuboids.end());

        vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];
        }

        int maxH = dp[0];

        for(int j = 1; j<n; j++) {
            for(int i = 0; i < j; i++) {
                if(cuboids[j][0] >= cuboids[i][0] and (cuboids[j][1] >= cuboids[i][1] and cuboids[j][2] >= cuboids[i][2])) {
                    dp[j] = max(dp[i] + cuboids[j][2], dp[j]);
                }
            }
            maxH = max(dp[j], maxH);
        }
        return maxH;
    }
};

// Time Complexity => O(n*n)
// Space Complexity => O(n)

// Not Accepted even after 1 hr into the question :"(
// Have to read the editorial
