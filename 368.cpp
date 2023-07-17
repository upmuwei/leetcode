class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), -1);
        vector<int> count(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0) {
                    if(count[j] + 1 > count[i]) {
                        count[i] = count[j] + 1;
                        dp[i] = j;
                    }
                }
            }
        }
        int max = 0;
        for(int i = 1; i < count.size(); i++) {
            if(count[i] > count[max]) {
                max = i;
            }
        }
        vector<int> result(count[max]);
        for(int j = result.size() - 1; j >= 0; j--) {
            result[j] = nums[max];
            max = dp[max];
        }
        return result;
    }
};