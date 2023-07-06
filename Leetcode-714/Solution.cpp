// Clarity Questions:
// What's the limit on prices.length?

// Intuition:
// There are a total of three scenorios in which you can imagine yourself on the ith day, all of those are listed below:
// 1.) You have the stock on that day either you bought it on that particular day or any other day before that day and you have not sold it yet
// 2.) You did have that stock previously but you sold it at that specific day
// 3.) You neither purchased the stock nor was it with you

// Approach:
// For the first scenario the profit would be calculated as -
// max(net profit if it was with you the day before, max(net profit if it was not with you on the day before, net profit if you sold this stock just the previous day) - prices[i])
// For the second scenario the net profit would be - net profit if it was with you the day before + prices[i] - fee
// For the third scenario the net profit would be - max(net profit if it was not with you on the day before, net profit if you sold this stock just the previous day)
// This way we will calculate the net profit in all of the 3 scenarios on every day
// And then pick the maximum out of them

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> possibleProfits(n, vector<int>(3));
        possibleProfits[0][0] = - prices[0];
        possibleProfits[0][1] = - fee;
        possibleProfits[0][2] = 0;
        // cout<<possibleProfits[0][0]<<" "<<possibleProfits[0][1]<<" "<<possibleProfits[0][2]<<endl;
        for(int i = 1; i < n; i++) {
            possibleProfits[i][0] = max(possibleProfits[i - 1][0], max(possibleProfits[i - 1][1], possibleProfits[i - 1][2]) - prices[i]);
            possibleProfits[i][1] = possibleProfits[i - 1][0] + prices[i] - fee;
            possibleProfits[i][2] = max(possibleProfits[i - 1][2], possibleProfits[i - 1][1]);
            // cout<<possibleProfits[i][0]<<" "<<possibleProfits[i][1]<<" "<<possibleProfits[i][2]<<endl;
        }
        return max(possibleProfits[n - 1][1], possibleProfits[n - 1][2]);
    }
};

// It took about 30 minutes.

// Time Complexity => O(n)
// Space Complexity => O(n)