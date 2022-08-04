class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int matrix[101][101] = {{0}};
        matrix[0][1] = 1;
        for(int i = 1; i <= obstacleGrid.size(); i++) {
            for(int j = 1; j <= obstacleGrid[0].size(); j++) {
                if(obstacleGrid[i-1][j-1] == 0) {
                    matrix[i][j] = matrix[i -1][j] + matrix[i][j -1];
                }
            }
        }
        return matrix[ obstacleGrid.size()][obstacleGrid[0].size()];
    }
};