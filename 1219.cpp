class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int max = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] != 0) {
                    int value = getValue(grid, i, j);
                    if(value > max) {
                        max = value;
                    }
                }
            }
        }
        return max;
    }

    int getValue(vector<vector<int>>& grid, int i, int j) {
        int max = 0;
        int t = grid[i][j];
        grid[i][j] = 0;
        if(i-1>=0&&grid[i - 1][j] != 0) {
            int v = getValue(grid, i - 1, j);
            if(v > max) {
                max = v;
            }
        }
        if(j-1>=0&&grid[i][j-1] != 0) {
            int v = getValue(grid, i, j - 1);
            if(v > max) {
                max = v;
            }
        }
        if(i+1 < grid.size()&&grid[i + 1][j] != 0) {
            int v = getValue(grid, i + 1, j);
            if(v > max) {
                max = v;
            }
        }
        if(j+1 < grid[i].size()&&grid[i][j + 1] != 0) {
            int v = getValue(grid, i, j + 1);
            if(v > max) {
                max = v;
            }
        }
        grid[i][j] = t;
        return max + t;
    }
};