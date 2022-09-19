class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> results(pairs.size());
        int max = 0;
        for(int i = 0; i < pairs.size(); i++) {
            results[i] = 1;
            int index, count = 0;
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0] && results[j] > count) {
                    count = results[j];
                }
            }
            results[i] += count;
            if(results[i] > max) {
                max = results[i];
            }
        }
        return max;
    }
};