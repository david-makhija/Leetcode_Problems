class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        sort(target.begin(), target.end());
        int sum = n;
        for(int i=0; i<n; i++) {
            if(target[i]!=sum) return false;
            sum += (sum-1);
        }
        return true;
    }
};
