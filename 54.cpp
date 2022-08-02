class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int lowHorizon = 0, highHorizon = matrix[0].size(), lowVerticality = matrix.size(), highVerticality = 0;  
        int i = 0, j = 0;
        while(true)  {
            for(; i < highHorizon; i++) {
                result.push_back(matrix[j][i]);
            }
            highVerticality++;
            i--;
            j++;

            for(; j < lowVerticality; j++) {
                result.push_back(matrix[j][i]);
            }
            highHorizon--;
            j--;
            i--;
            
            for(; i >= lowHorizon&&j>=highVerticality; i--) {
                result.push_back(matrix[j][i]);
            }
            lowVerticality--;
            i++;
            j--;
            for(;j >= highVerticality&&i<highHorizon; j--) {
                result.push_back(matrix[j][i]);
            }
            lowHorizon++;
            j++;
            i++;
            if(lowHorizon >= highHorizon || highVerticality >= lowVerticality) {
                break;
            }
        }
        return result;
     }
};