class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for(int i = 3; i <= n; i++) {
            int j = i - 1;
            int middle = i / 2;
            while(j >= middle) {
                int max1 = max(dp[j], j);
                int max2 = max(dp[i - j], i - j);
                int t = max1 * max2;
                dp[i] = max(t, dp[i]);
                j--;
            }
        }
        return dp[n];
    }
};