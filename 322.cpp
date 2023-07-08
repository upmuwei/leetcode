class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int num = -1;
        if(amount == 0) {
            return 0;
        }

        vector<int> dp(amount + 1, 10001);
        for(int coin : coins) {
            if(coin >= dp.size()) {
                continue;
            }
            dp[coin] = 1;
        }
        for(int i = 1; i < dp.size(); i++) {
            for(int coin : coins) {
                if(coin < i && 1 + dp[i - coin] < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                }
            }
        }
        if(dp[amount] == 10001) {
            return -1;
        }
        return dp[amount];
    }
};