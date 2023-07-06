// Clarity Questions:
// What is the max value of grid.length and the max value of grid[0].length
// What is the max value of (grid.length) * (grid[0].length)

// Intuition:
// If I was given this grid what I would do with it is that - I would choose the smallest element in the grid
// And turn it into the smallest positive number that is 1
// Because this element is smaller than every other element simultaneously 1 is the smallest positive integer
// Now there is a lower limit on the elements that have a common row or column with this element and thatm limit is this element
// Thus in the beginning the lower limit of every row and column is 0 
// We will keep updating the elements in this grid such that both the lower limits of its row and column is strictly less than this new updated value

// Approach:
// We have declared an ordered set of vectors which stores all the elements of grid in the format -
// {grid[i][j], i, j} we will keep extracting the first element because its the smallest one 
// We will update its value according to the lower limit and subsequently update the lower limit of respective row and column

class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<int>> elements;
        vector<int> prevMinAmongRow(n, 0);
        vector<int> prevMinAmongCol(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                elements.insert({grid[i][j], i, j});
            }
        }

        while(!elements.empty()) {
            int i = (*elements.begin())[1], j = (*elements.begin())[2];
            elements.erase(elements.begin());
            grid[i][j] = max(prevMinAmongRow[i], prevMinAmongCol[j]) + 1;
            prevMinAmongRow[i] = grid[i][j];
            prevMinAmongCol[j] = grid[i][j];
        }

        return grid;
    }
};

// Intuition built in 33 minutes

// Time Complexity => m * n * log(m * n)
// Space Complexity => m * n