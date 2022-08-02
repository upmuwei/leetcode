class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int p[201][201] = {{0}};
        for(int i = 2; i <= grid[0].size(); i++) {
            p[0][i] = 501;
        }
        for(int j = 2; j <= grid.size(); j++) {
            p[j][0] = 501;
        }
        for(int i = 1; i <= grid.size(); i++) {
            for(int j = 1; j <= grid[0].size(); j++) {
                p[i][j] = (p[i-1][j] > p[i][j-1] ? p[i][j-1] : p[i-1][j] ) + grid[i-1][j-1];
            }
        }
        return p[grid.size()][grid[0].size()];
    }
};