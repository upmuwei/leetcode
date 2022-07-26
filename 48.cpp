class Solution {
public:
    // （j, n -i）
    void rotate(vector<vector<int>>& matrix) {
        for(int i =0; i < matrix.size()/2; i++) {
            for(int j = i; j < matrix.size() - i - 1; j++) {
                int n = matrix.size() - 1;
                int t = matrix[i][j];
                int k = j, p = n - i;
                int u;
                while(!(k == i && p == j)) {
                    u = matrix[k][p];
                    matrix[k][p] = t;
                    int tmp = k;
                    k = p;
                    p = n - tmp;
                    t = u;
                }  
                matrix[k][p] = t;    
            }
        }
    }
};