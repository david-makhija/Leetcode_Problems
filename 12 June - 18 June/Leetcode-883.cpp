class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size(), sum=0;
        for(int i=0; i<n; i++) {
            int maxRow = 0, maxCol = 0;
            for(int j=0; j<n; j++) {
                if(grid[i][j]>0) sum++;
                if(grid[i][j]>maxRow) maxRow = grid[i][j];
                if(grid[j][i]>maxCol) maxCol = grid[j][i];
            }
            sum += maxRow;
            sum += maxCol;
        }
        return sum;
    }
};