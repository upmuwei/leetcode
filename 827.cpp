// class Solution {
// public:
//     int largestIsland(vector<vector<int>>& grid) {
//         int max = 0, now = 0;
//         vector<vector<bool>> looked(grid.size(), vector<bool>(grid.size(), false));
//         for(int i = 0; i < grid.size(); i++) {
//             for(int j = 0; j < grid.size(); j++) {
//                 if(grid[i][j] == 0) {
//                     grid[i][j] = 1;
//                     seek(grid, looked, now, i, j);
//                     grid[i][j] = 0;  
//                     if(now > max) {
//                         max = now;
//                     }
//                     if(now == 1) {
//                         looked[i][j] = false;
//                     } else {
//                         for(int i = 0; i < grid.size(); i++) {
//                             for(int j = 0; j < grid.size(); j++) {
//                                 looked[i][j] = false;
//                             }
//                         }
//                     }
//                     now = 0;
//                 }
//             }
//         }
//         return (max == 0 ? grid.size() * grid.size() : max);
//     }

//     void seek(vector<vector<int>>& grid, vector<vector<bool>>& looked, int& now, int i, int j) {
//             looked[i][j] = true;
//             now++;
//             if(i + 1 < grid.size() && !looked[i + 1][j] && grid[i + 1][j]) {
//                 seek(grid, looked, now, i + 1, j);
//             }
//             if(j + 1 < grid.size() && !looked[i][j + 1] && grid[i][j + 1]) {
//                 seek(grid, looked, now, i, j + 1);
//             }
//             if(j - 1 >= 0 && !looked[i][j - 1] && grid[i][j - 1]) {
//                 seek(grid, looked, now, i, j - 1);
//             }
//             if(i - 1 >= 0 && !looked[i - 1][j] && grid[i - 1][j]) {
//                 seek(grid, looked, now, i - 1, j);
//             }
//     }
// };
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int max = 0, now = 1;
        map<int, int> islands;
        vector<vector<bool>> looked(grid.size(), vector<bool>(grid.size(), false));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                if(grid[i][j] != 0 && !looked[i][j]) {
                    int index = i * grid.size() + j + 1;
                    islands[index] = 0;
                    seek(grid, looked, islands, index, i, j);
                    
                }
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                if(grid[i][j] == 0) {
                    merge(grid, islands, now, i, j);
                    if(now > max) {
                        max = now;
                    }
                    now = 1;
                }
            }
        }
        return (max == 0 ? grid.size() * grid.size() : max);
    }

    void merge(vector<vector<int>>& grid, map<int, int>& islands, int& now, int i, int j) {
        set<int> noRepeat;
        if(i + 1 < grid.size() && grid[i + 1][j]) {
            noRepeat.insert(grid[i + 1][j]);
        }
        if(j + 1 < grid.size() && grid[i][j + 1]) {
            noRepeat.insert(grid[i][j + 1]);
        }
        if(j - 1 >= 0 && grid[i][j - 1]) {
            noRepeat.insert(grid[i][j - 1]);
        }
        if(i - 1 >= 0 && grid[i - 1][j]) {
            noRepeat.insert(grid[i - 1][j]);
        }
        for(auto index : noRepeat) {
            now += islands[index];
        }
    }
    void seek(vector<vector<int>>& grid, vector<vector<bool>>& looked, map<int, int>& islands, int index, int i, int j) {
            grid[i][j] = index;
            islands[index]++;
            looked[i][j] = true;
            if(i + 1 < grid.size() && !looked[i + 1][j] && grid[i + 1][j]) {
                seek(grid, looked, islands, index, i + 1, j);
            }
            if(j + 1 < grid.size() && !looked[i][j + 1] && grid[i][j + 1]) {
                seek(grid, looked, islands, index, i, j + 1);
            }
            if(j - 1 >= 0 && !looked[i][j - 1] && grid[i][j - 1]) {
                seek(grid, looked, islands, index, i, j - 1);
            }
            if(i - 1 >= 0 && !looked[i - 1][j] && grid[i - 1][j]) {
                seek(grid, looked, islands, index, i - 1, j);
            }
    }
};