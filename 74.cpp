class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        for(; i < matrix.size(); i++) {
            if(matrix[i][0] >= target) {
                if(matrix[i][0] == target) {
                    return true;
                }
                break;
            }
        }
        i--;
        if(i < 0) {
            return false;
        }
        for(int j = 0; j < matrix[0].size(); j ++) {
            if(matrix[i][j] == target) {
                return true;
            }
        }
    
        return false;
    }
};