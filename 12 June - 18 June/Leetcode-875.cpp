class Solution {
    int calculateHours(int k, vector<int>& piles, int n) {
        int totalHours = 0;
        for(int i=0; i<n; i++) {
            totalHours += ceil(((double)piles[i])/((double)k));
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxB = 0;
        int n = piles.size();
        for(int i=0; i<n; i++) {
            maxB = max(maxB, piles[i]);
        }
        int st = 1, en = maxB+1;
        while(st<en) {
            int mid = st + ((en-st)/2);
            int ht = calculateHours(mid, piles, n);
            cout<<mid<<", "<<ht<<endl;
            if(ht<=h) en = mid;
            else st = mid+1;
        }
        return st;
    }
};