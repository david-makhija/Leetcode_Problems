// Clarity Questions:
// What's the limit of Fuel?
// Is there any limit on the size of locations?
// Limit on the max element in the array locations?
// While discovering a path can cycles exist in it?


// First I was thinking about recursion because when we are at any position index 'i' we have n - 1 number of choices to explore.
// But with recursion the Time Complexity will become exponential that is O(n ^ fuel).
// So as to reduce the Time Complexity with a sort of similar approach, I started looking for repeating subproblems, below is the explanation of what kind of repeating subproblems are there and how to build the final answer from these subproblems: 

// Start reading from the public functions, please read the other functions whenever they are called.
class Solution {
    int mod = 1e9 + 7;
    
    int countingRoutes(vector<int>& locations, int remFuel, int currPosIdx, int n, vector<vector<int>>& dp, int maxFuel) {
        // All about the variables:
        // currPosIdx signifies that the traveller is standing at locations[currPosIdx] at this instance.
        // remFuel signifies the remaining fuel at this location.
        // maxFuel is the limit that remFuel can hold at a given instance
        if(dp[remFuel][currPosIdx] != -1) {
            return dp[remFuel][currPosIdx];
        }
        
        dp[remFuel][currPosIdx] = 0;
        for(int i=0; i<n; i++) {
            // Suppose if someone is at locations[currPosIdx] with remaining Fuel as remFuel then they must have reached here from locations[i] when they had the remaining fuel as remFuel + abs( locations[i] - locations[currPosIdx] ) at locations[i] where i != currPosIdx.
            // Thus we must perform the summation dp[remFuel + abs( locations[i] - locations[currPosIdx] )][i] in order to get to the answer of current subproblem.
            // If we need to more fuel than maxFuel in order to go from locations[i] to locations[currPosIdx] then the underlying travel is not possible.
            dp[remFuel][currPosIdx] = ( (remFuel + abs( locations[i] - locations[currPosIdx] ) <= maxFuel) and (i != currPosIdx) ) ? ((  (long long) dp[remFuel][currPosIdx] + (long long) countingRoutes(locations, remFuel + abs( locations[i] - locations[currPosIdx] ), i, n, dp, maxFuel)  ) % mod) : dp[remFuel][currPosIdx];

        }

        return dp[remFuel][currPosIdx];
    }


public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        
        // I am defining my subproblems as dp[i][j] = number of ways we can reach to the locations[j] whenever the amount of fuel left at this location is equal to i.
        vector<vector<int>> dp( fuel + 1 , vector<int>( n , -1 ) );  
        
        // As you can see the base case here is dp[fuel][start] = 1.
        dp[fuel][start] = 1;
        
        // So by the definition of 2d vector dp you must know that all we need is the sum of routes to finish whenever the traveller has i fuel where 0 <= i <= fuel.
        // And that sum will be stored in the variable allPossibleRoutes which is calculated as follows:
        int allPossibleRoutes = 0;
        for(int i=0; i<=fuel; i++) {
            // Go to see the called function to understand the workings of this function in order to understand this better.
            dp[i][finish] = countingRoutes( locations, i, finish, n, dp, fuel );
            int temp = dp[i][finish];
            allPossibleRoutes = ( (long long) allPossibleRoutes + (long long) temp ) % mod;
        }


        return allPossibleRoutes;
    }

    
};

// Verdict: accepted after 2 hours of struggle :/

// Space Complexity => O(fuel * n)
// Time Complexity => O(fuel * n)

// Questions:
// If I am typecasting the 2d array element at line 55 it gives me runtime error whereas if I do this at line 30 no such error pops up?
