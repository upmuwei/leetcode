class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int max = 0;
        int t = 0;
        for(int i = 1; i < temperatureA.size(); i++) {
            if(temperatureA[i] - temperatureA[i-1] > 0) {
                if(temperatureB[i] - temperatureB[i-1] > 0) {
                    t++;
                }else {
                    t = 0;
                }
            } else if(temperatureA[i] - temperatureA[i-1] < 0) {
                if(temperatureB[i] - temperatureB[i-1] < 0) {
                    t++;
                }else {
                    t = 0;
                }
            } else {
                if(temperatureB[i] - temperatureB[i-1] == 0) {
                    t++;
                }else {
                    t = 0;
                }
            }
            if(t > max) {
                max = t;
            }
        }
        return max;
    }
};