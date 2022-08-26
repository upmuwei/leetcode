class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max;
        vector<int> sums(values.size());
        sums[0] = 0;
        max = sums[1] = values[1] + values[0] - 1;
        for(int i = 2; i < values.size(); i++) {
            int t1 = values[i] + values[i-1] - 1;
            int t2 = values[i] + sums[i-1] - values[i-1] -1;
            sums[i] = (t1 > t2 ? t1 :t2);
            if(sums[i] > max) {
                max = sums[i];
            }
        }
        return max;
    } 
};