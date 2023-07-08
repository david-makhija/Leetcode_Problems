// Clarity Questions:
// What's the limit on weights.size()?
// What's the limit on k?

// Intuition:
// We just have to calculate the minimum and maximum cost of partitioning and then subtract the former from the latter
// First we focus on calculating the minimum cost with partitions (maximum can be calculated in a similar fashion)
// While building up the solution we know that for sure the first and last element of this array must be included in the answer
// The next step would be to find k - 1 different partitions in the array - such that the resultant cost is minimum
// Thus, in simpler words we just need to look after k - 1 consecutive pairs of integers in the array such that their pair-wise collective sum is minimal

// Approach:
// To calculate the minimum and maximum possible costs we have the variables - minAns and maxAns respectively
// To help calculate these we have the priority queues - minPairs and maxPairs 
// These are min and max priority queues respectively
// We will store all the n - 1 pair partition costs in these priority queues
// After that we can easily obtain the greatest and least k - 1 pair partition costs

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        priority_queue<int> maxPairs;
        priority_queue<int, vector<int>, greater<int>> minPairs;

        long long minAns = weights[0] + weights[n - 1];
        long long maxAns = weights[0] + weights[n - 1];
        for(int i = 0; i < n - 1; i++) {
            maxPairs.push(weights[i] + weights[i + 1]);
            minPairs.push(weights[i] + weights[i + 1]);
        }

        for(int i = 0; i < k - 1; i++) {
            maxAns += maxPairs.top();
            maxPairs.pop();
            minAns += minPairs.top();
            minPairs.pop();
        }
        return maxAns - minAns;
    }
};
// Memory Limit Exceeded after 30 minutes
// Accepted after another 30 minutes into the question

// Time Complexity => O(weights.length*log(weights.length))
// Space Complexity => O(weights.length)