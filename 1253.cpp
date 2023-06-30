class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> result(2, vector<int>(colsum.size()));
        int sum = 0;
        int exist = 0;
        for(int i = 0; i < colsum.size(); i++) {
            sum += colsum[i];
            if(colsum[i] == 2) {
                result[0][i] = 1;
                result[1][i] = 1;
                exist++;
            }
        }
        if(sum != upper + lower || upper < exist || lower < exist) {
            return {};
        }
        upper -= exist;
        lower -= exist;
        for(int i  = 0; i < colsum.size(); i++) {
            if(colsum[i] == 1) {
                if(upper != 0) {
                    result[0][i] = 1;
                    result[1][i] = 0;
                    upper--;
                } else {
                    result[0][i] = 0;
                    result[1][i] = 1;
                }
            }
        }
        return result;
    }
};