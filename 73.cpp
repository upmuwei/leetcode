class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //二层vector不好用
        vector<int> rowIndex, colIndex;
        //size替换，节省时间
        int length1 = matrix.size(), length2 = matrix[0].size();
        for(int i = 0; i <  length1; i++) {
            for(int j = 0; j < length2; j++) {
                if(matrix[i][j] == 0) {
                    rowIndex.push_back(i);
                    colIndex.push_back(j);
                }
            }
        }
        for(auto t : colIndex) {
            for(int i = 0; i < length1; i++) {
                matrix[i][t] = 0;
            }
        }
        for(auto t : rowIndex) {
            for(int j = 0; j < length2; j++) {
                matrix[t][j] = 0;
            }
        }
    }
};