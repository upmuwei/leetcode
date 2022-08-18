class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        int result[nums.size()];
        result[0] = nums[0];
        result[1] = nums[1];
        result[2] = nums[2] + result[0];
        for(int i = 3; i < nums.size(); i++) {
            result[i] = nums[i] + (result[i-2] > result[i-3] ? result[i-2] :result[i-3]);
        }
        return result[nums.size() - 1] > result[nums.size() - 2] ? result[nums.size() - 1] : result[nums.size() - 2];
    }
};