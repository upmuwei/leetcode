class Solution {
public:
    //状态机
    int maxProfit(vector<int>& prices) {
        vector<int> buys(prices.size());
        vector<int> sales(prices.size());
        vector<int> waits(prices.size());
        sales[0] = 0;
        waits[0] = 0;
        buys[0] = - prices[0];
        for(int i = 1; i < prices.size(); i++) {
            buys[i] = max(waits[i - 1] - prices[i], buys[i - 1]);
            waits[i] = max(waits[i - 1], sales[i - 1]);
            sales[i] = buys[i - 1] + prices[i];
        }

        return max(buys[prices.size() - 1], max(sales[prices.size() - 1], waits[prices.size() - 1]));
    }
};