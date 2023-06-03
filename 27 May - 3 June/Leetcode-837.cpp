#include <bits/stdc++.h>
using namespace std;

class Solution {
    void countOutcomes(int target, int maxPts, int currScore, vector<int>& countOfOutcomes, int currTile) {
        countOfOutcomes[currScore]++;
        if(currScore>=target) return;
        for(int i=1; i<=maxPts; i++) {
            countOutcomes(target, maxPts, currScore+i, countOfOutcomes, i);
        }
    }
public:
    double new21Game(int n, int k, int maxPts) {
        vector<int> countOfOutcomes(k+maxPts, 0);
        countOutcomes(k, maxPts, 0, countOfOutcomes, 1);
        double totalOutcomes = 0.0, favOutcomes = 0.0;
        for(int i=k; i<k+maxPts; i++) {
            if(i<=n) favOutcomes += ((double)countOfOutcomes[i]);
            totalOutcomes += ((double)countOfOutcomes[i]);
        }
        return favOutcomes/totalOutcomes;
    }
};