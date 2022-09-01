class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result(prices.size());
        for(int i = 0; i < prices.size(); i++) {
            int t = prices[i];
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] <= t) {
                    t -= prices[j];
                    break;
                }
            }
            result[i] = t;
        }
        return result;
    }
};