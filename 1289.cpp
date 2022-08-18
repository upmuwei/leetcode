class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int length = grid.size(), width = grid[0].size();
        int min, index = 0, secMin;
        int lastMin = 0, lastIndex = 0, lastSecMin = 0;
        for(int i = 0; i < length; i++) {
            min = 20000;
            secMin = 20000;
            for(int j = 0; j < width; j++) {
                if(lastIndex == j ) {
                     grid[i][j] += lastSecMin;
                     
                } else {
                     grid[i][j] += lastMin;
                }
                if(grid[i][j] < min) {
                    if(min < secMin) {
                        secMin = min;
                    }
                    min = grid[i][j];
                    index = j;
                } else if(grid[i][j] < secMin){
                    secMin = grid[i][j];
                }
            }
           // cout << min  << " " << secMin << endl;
            lastMin = min;
            lastIndex = index;
            lastSecMin = secMin;
        }
        return min;
    }
};