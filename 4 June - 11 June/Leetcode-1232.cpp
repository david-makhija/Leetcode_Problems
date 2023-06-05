class Solution {
    double findSlope(int x1, int x2, int y1, int y2) {
        return ((double)y2-(double)y1)/((double)x2-(double)x1);
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(coordinates[0][0]==coordinates[1][0]) {
            for(int i=2; i<n; i++) {
                if(coordinates[i][0]!=coordinates[i-1][0]) return false;
            }
            return true;
        }
        double slope = findSlope(coordinates[0][0], coordinates[1][0], coordinates[0][1], coordinates[1][1]);
        for(int i=2; i<n; i++) {
            if(slope!=findSlope(coordinates[i-1][0], coordinates[i][0], coordinates[i-1][1], coordinates[i][1])) {
                return false;
            }
        }
        return true;
    }
};