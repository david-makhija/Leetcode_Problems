class Solution {
    double ans = 0;

    void calcProb(vector<double>& prob, int idx, int target, vector<bool>& isHeads, double currProb, int n) {
        ans += currProb;

        for(int i = idx; i < target; i++) {
            for(int j = target; j < n; j++) {
                if(isHeads[j]) {
                    continue;
                }
                isHeads[i] = false, isHeads[j] = true;
                calcProb(prob, i + 1, target, isHeads, currProb * prob[j] / prob[i] * (1 - prob[i]) / (1 - prob[j]), n);
                isHeads[i] = true, isHeads[j] = false;
            }
        }
    }
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        double currProb = 1.0;
        int n = prob.size();
        
        vector<double> newProb;
        for(int i = 0; i < n; i++) {
            if(prob[i] > 0 and prob[i] < 1) {
                newProb.push_back(prob[i]);
            }
            else if(prob[i] == 1) {
                target--;
            }
        }
        n = newProb.size();
        if(target > n or target < 0) {
            return 0;
        }
        vector<bool> isHeads(n, false);

        for(int i=0; i<n; i++) {
            if(i < target) {
                currProb *= newProb[i];
                isHeads[i] = true;
            }
            else {
                currProb *= (1 - newProb[i]);
            }
        }

        calcProb(newProb, 0, target, isHeads, currProb, n);

        return ans;
    }
};

// TLE (after 14:30 minutes into the question)
// Wrong Answer (after another 28 minutes into the question)
// Wrong Answer (after another 11 minutes into the question)
// Wrong Answer (after another 5 minutes into the question)