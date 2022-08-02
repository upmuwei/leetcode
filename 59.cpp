class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        for(int i =0; i < n; i++) {
            vector<int> tmp;
            for(int j = 0; j < n; j++) {
                tmp.push_back(0);
            }
            matrix.push_back(tmp);
        }
        int lowHorizon = 0, highHorizon = n, lowVerticality = n, highVerticality = 0;  
        int i = 0, j = 0;
        int t = 1;
        while(true)  {
            for(; i < highHorizon; i++) {
                matrix[j][i] = t++;
            }
            highVerticality++;
            i--;
            j++;

            for(; j < lowVerticality; j++) {
                matrix[j][i]  = t++;
            }
            highHorizon--;
            j--;
            i--;
            
            for(; i >= lowHorizon&&j>=highVerticality; i--) {
                matrix[j][i] = t++;
            }
            lowVerticality--;
            i++;
            j--;
            for(;j >= highVerticality&&i<highHorizon; j--) {
                matrix[j][i] = t++;
            }
            lowHorizon++;
            j++;
            i++;
            if(lowHorizon >= highHorizon || highVerticality >= lowVerticality) {
                break;
            }
        }
        return matrix;
    }
};