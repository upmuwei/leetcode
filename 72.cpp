class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> matrix(word1.size() +1, vector<int>(word2.size() +1, 0));
        for(int i = 1; i < matrix[0].size(); i++) {
            matrix[0][i] = i;
        }
        for(int i = 1; i < matrix.size(); i++) {
            matrix[i][0] = i;
        }
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                matrix[i][j] = (min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]))) + 1;
                if(word1[i - 1] == word2[j - 1]) {
                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][j - 1]);
                }
            }
        }
        return matrix[word1.size()][word2.size()];
    }
};