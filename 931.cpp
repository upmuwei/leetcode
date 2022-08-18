class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int length = matrix.size(), width = matrix[0].size();
        for(int i = 1; i < length; i++) {
            for(int j = 0; j < width; j++) {
                if(j == 0) {
                    matrix[i][j] += (matrix[i-1][j] > matrix[i-1][j+1]? matrix[i-1][j + 1] : matrix[i-1][j]);
                }else if(j == width - 1) {
                     matrix[i][j] += (matrix[i-1][j] > matrix[i-1][j-1]? matrix[i-1][j - 1] : matrix[i-1][j]);
                } else {
                    int t = (matrix[i-1][j] > matrix[i-1][j-1]? matrix[i-1][j - 1] : matrix[i-1][j]);
                    matrix[i][j] += (t > matrix[i-1][j + 1] ? matrix[i-1][j +1] : t);
                }
            }
        }
        int min = matrix[length - 1][0];
        for(int j = 1; j < width; j ++) {
            if(matrix[length -1][j] < min) {
                min = matrix[length - 1][j];
            }
        }
        return min;
    }
};