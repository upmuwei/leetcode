class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int *dp = new int[nums.size()];
        int max = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    int t = dp[j] + 1;
                    if(t > dp[i]) {
                        dp[i] = t;
                    }
                }
            }
            if(dp[i] > max) {
                max = dp[i];
            }
        }

        return max;
    }
};