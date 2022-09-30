class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeros;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    vector<int> t(2, 0);
                    t[0] = i;
                    t[1] = j;
                    zeros.push_back(t);
                }
            }
        }
        for(int i = 0; i < zeros.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                matrix[j][zeros[i][1]] = 0;
            }
            for(int k = 0; k < matrix[0].size(); k++) {
                matrix[zeros[i][0]][k] = 0;
            }
        }
    }
};