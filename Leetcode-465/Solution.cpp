// Clarity Questions :
// What's the limit on the number of transactions
// What's the limit on amounti?
// Can a reverse transaction happen in this problem? (i.e. first a gives b then b gives a)

class Solution {

    // Intuition :
    // This is a basic recursive solution where in each iteration we do a transaction from the current user 
    // to any user with credit balance that has the opposite sign of this user's credit balance.
    // But before this we make a record of net credit balance of each individual.  

    int dfs(vector<int>& balanceList, int cur, int n) {
        // Now coming onto the workings of this function:
        // This function returns the minimum number of transactions to resolve the debt of individuals coming after cur given that the debt individuals before cur is resolved
        // to optimize this while we search for a needful candidate to make a transaction with cur we ensure that the sign of the net balance of that individual is opposite then this guy

        while(cur < n and balanceList[cur] == 0) {
            cur++;
        }

        if(cur == n) {
            return 0;
        }

        int minTransactions = INT_MAX;
        for(int i = cur + 1; i < n; i++) {
            if(balanceList[i] * balanceList[cur] < 0) {
                balanceList[i] = balanceList[i] + balanceList[cur];
                minTransactions = min(minTransactions, dfs(balanceList, cur + 1, n) + 1);
                balanceList[i] = balanceList[i] - balanceList[cur];
            }
        }

        return minTransactions;
    }

public:
    int minTransfers(vector<vector<int>>& transactions) {
        // This map stores the net debts of the individuals
        // i.e. creditMap[i] = either what other n - 1 people collectively owe this individual or what this individual owes to the other n - 1 people.
        // if other people owe the money to this individual then this value would be +ve else it would be negative
        unordered_map<int, int> creditMap;
        for(vector<int> x: transactions) {
            creditMap[x[0]] += x[2];
            creditMap[x[1]] -= x[2];
        }

        // Next we eliminate those candidates that have a net credit balance as zero
        vector<int> balanceList;
        for(auto itr = creditMap.begin(); itr != creditMap.end(); itr++) {
            if(itr->second != 0) {
                balanceList.push_back(itr->second);
            }
        }

        return dfs(balanceList, 0, balanceList.size());
    }
};

// Time Complexity => O((transaction.length)!)
// Space Complexity => O(transaction.length)

// Not done by me had to read the editorial :(