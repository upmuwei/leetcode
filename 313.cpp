class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> nums(primes.size(), 1);
        int* dp = new int[n + 1];
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            long min = primes[0] * (long)dp[nums[0]];
            for(int j = 1; j < primes.size(); j++) {
                long t = primes[j] * (long)dp[nums[j]];
                if(t <  min) {
                    min = t;
                }
            }
            dp[i] = min;
            for(int j = 0; j < primes.size(); j++) {
                if(min == primes[j] * (long)dp[nums[j]]) {
                    nums[j]++;
                }
            }
        }
        return dp[n];
    }
};