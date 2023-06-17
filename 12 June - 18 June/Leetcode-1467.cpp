class Solution {
    int favCases = 0, totalCases = 0;
    void calculateCases(vector<int>& balls, int box1, int box2, int capacity1, int capacity2, int db1, int db2, vector<vector<int>>& bitmasks, int k) {
        if(capacity1==0 and capacity2==0) {
            if(db1==db2) {
                if(bitmasks[box1][box2]!=2) {
                    bitmasks[box1][box2] = 2;
                    favCases++;
                    totalCases++;
                }
            }
            else if(bitmasks[box1][box2]!=1) {
                bitmasks[box1][box2] = 1;
                totalCases++;
            }
            return;
        }
        if(capacity1>0) {
            for(int i=0; i<k; i++) {
                if(balls[i]>0) {
                    balls[i]--;
                    int temp = ((1<<i)|box1);
                    int f = db1;
                    if(box1!=temp) f++;
                    calculateCases(balls, temp, box2, capacity1-1, capacity2, f, db2, bitmasks, k);
                    balls[i]++;
                }
            }
        }
        if(capacity2>0) {
            for(int i=0; i<k; i++) {
                if(balls[i]>0) {
                    balls[i]--;
                    int temp = ((1<<i)|box2);
                    int f = db2;
                    if(box2!=temp) f++;
                    calculateCases(balls, box1, temp, capacity1, capacity2-1, db1, f, bitmasks, k);
                    balls[i]++;
                }
            }
        }
    }
public:
    double getProbability(vector<int>& balls) {
        int k = balls.size();
        int m = accumulate(balls.begin(), balls.end(), 0);
        int n = m/2;
        int box1 = 0;
        int box2 = 0;
        vector<vector<int>> bitmasks(pow(2, k), vector<int>(pow(2, k), 0));
        calculateCases(balls, box1, box2, n, n, 0, 0, bitmasks, k);
        return ((double)favCases/(double)totalCases);
    }
};