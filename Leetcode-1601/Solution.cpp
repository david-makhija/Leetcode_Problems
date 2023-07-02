// Clarity Questions :
// What's the maximum size of requests array?
// Maximum value of n?

class Solution {

    // Intuition :
    // This is a recursion solution using bitmasking,
    // Basically we are going through all of the requests and for each request we explore 2 possibilities 
    // Either we consider that request or we do not
    // After we have gone through all of the requests we check if the netBalance of all the buildings is zero or not.

    int eligibleRequests(vector<vector<int>>& requests, int cur, vector<int>& netBalance, int m, int n, int balanceNotGood) {
        // cur == m means we have gone through all of the requests once 
        // balanceNotGood is a variable that is used to determine whether if the net Balance is 0 for all the buildings or not if it is zero then net balance for all the buildings is zero
        // if -1 is returned then it is a sign that the considered set of requests were not eligible.
        if(cur == m) {
            return (balanceNotGood == 0) ? 0 : -1;
        }

        // "withoutThis" variable stores the maximum number of eligible requests in the range [cur+1:] when we do not include the current requests
        int maxRequests = -1;
        int withoutThis = eligibleRequests(requests, cur + 1, netBalance, m, n, balanceNotGood);
        maxRequests = max(maxRequests, withoutThis);
        
        
        // "withThis" variable stores the number of eligible transactions in the range [cur+1:] when we do consider the current request
        // here we are recalculating the netBalance of buildings involved in this request
        // Subsequently we also recalculate the variable balanceNotGood
        // we set the ith bit 1 if the netBalance of that building is non Zero
        // else we set that bit as zero 
        netBalance[requests[cur][0]] ++;
        netBalance[requests[cur][1]] --;
        if(netBalance[requests[cur][0]] != 0) {
            balanceNotGood = balanceNotGood | (1 << requests[cur][0]);
        }
        else {
            balanceNotGood &= ~(1UL << requests[cur][0]);
        }
        if(netBalance[requests[cur][1]] != 0) {
            balanceNotGood = balanceNotGood | (1 << requests[cur][1]);
        }
        else {
            balanceNotGood &= ~(1UL << requests[cur][1]);
        }

        int withThis = eligibleRequests(requests, cur + 1, netBalance, m, n, balanceNotGood);
        maxRequests = (withThis != -1) ? max(maxRequests, withThis + 1) : maxRequests;
        netBalance[requests[cur][0]] --;
        netBalance[requests[cur][1]] ++;

        return maxRequests;
    }

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // netBalance[i] contains the net shift of employees i.e. aggregate of the number of employees entering and leaving the ith building.
        // It is positive if more people have left the company as compared to the number of people coming in.
        vector<int> netBalance(n, 0);

        int m = requests.size();
        int maxRequests = eligibleRequests(requests, 0, netBalance, m, n, 0);
        return maxRequests == -1 ? 0 : maxRequests;
    }
};

// Accepted in 42 minutes

// Time Complexity => O(2^(requests.length))
// Space Complexity => O(n)
