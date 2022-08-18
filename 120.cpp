class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int p[201][202];
        for(int i = 0; i <= 200; i++) {
            for(int j = 0; j <= 200; j++) {
                p[i][j] = 10000;
            }
        }
        p[0][0] = 0;
        for(int i = 1; i <= triangle.size(); i++) {
            for(int j = 1; j <= triangle[i - 1].size(); j++) {
                p[i][j] = triangle[i -1][j -1] + (p[i-1][j] > p[i-1][j-1] ? p[i-1][j-1] : p[i-1][j]);
            }
        }
        int min = p[triangle.size()][1], length = triangle[0].size() -1 + triangle.size();
        for(int j = 2; j <= length; j++) {
            if(p[triangle.size()][j] < min) {
                min = p[triangle.size()][j];
            }
        }
        return min;
       
    }
};