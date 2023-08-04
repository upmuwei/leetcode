class Solution {
    int count = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return census(nums, 0, target);
    }
    
    int census(vector<int>& nums, int index, int target) {
        if(index == nums.size()) {
            if(target == 0) {
                return 1;
            }
            return 0;
        }
        return census(nums, index + 1, target - nums[index]) + census(nums, index + 1, target + nums[index]);
    }
};