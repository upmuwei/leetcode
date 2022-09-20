class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> looked(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1' && !looked[i][j]) {
                    count++;
                    islooked(grid, looked, i, j);
                }
            }
        }
        return count;
    }

    void islooked(vector<vector<char>>& grid, vector<vector<bool>>& looked, int i, int j) {
        looked[i][j] = true;
        if(i-1>=0&&grid[i-1][j] == '1' && !looked[i - 1][j]) {
            islooked(grid, looked, i -1, j);
        }
        if(j-1>=0&&grid[i][j-1] == '1' && !looked[i][j - 1]) {
            islooked(grid, looked, i, j - 1);
        }
        if(i+1<grid.size()&&grid[i+1][j] == '1' && !looked[i+1][j]) {
            islooked(grid, looked, i+1, j);
        }
        if(j+1<grid[i].size()&&grid[i][j+1] == '1' && !looked[i][j+1]) {
            islooked(grid, looked, i, j + 1);
        }
    }
};