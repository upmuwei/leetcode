class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int max = 0;
        for(int i = 0; i <= grid.size() - 3; i++) {
            for(int j = 0; j <= grid[0].size() - 3; j++) {
                int t = sum(grid, i, j);
                if(t > max) {
                    max = t;
                }
            }
        }
        return max;
    }
    
    int sum(vector<vector<int>>& grid, int i, int j) {
        int sum = 0;
        for(int k = j; k < j + 3; k++) {
            sum += grid[i][k];
            sum += grid[i + 2][k];
        }
        return sum + grid[i + 1][j + 1];
    }
};