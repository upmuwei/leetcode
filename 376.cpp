class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) {
            return nums.size();
        }
        int inceased = 0;
        vector<int> dp(nums.size(), 1);
        for(int i = 1;  i < nums.size(); i++) {
            if(inceased * (nums[i] - nums[i - 1] ) < 0) {
                dp[i] = dp[i - 1] + 1;
            } else if(!inceased && (nums[i] != nums[i - 1]) ){  
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = dp[ i - 1];
            }
            if(nums[i] != nums[i - 1]) {
                inceased = (nums[i] - nums[i - 1] > 0 ? 1 : - 1);
            } 
            
        }
        return dp[nums.size() - 1];
    }
};