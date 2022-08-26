class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int now = 0, max = 0;
        for(int i = 1; i < prices.size(); i++) {
            now += prices[i] - prices[i-1];
            if(now < 0) {
                now = 0;
            }
            if(now > max) {
                max = now;
            }
        }
        return max;
    }
};