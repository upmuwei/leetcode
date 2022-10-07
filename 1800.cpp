class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int t = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                t += nums[i];
            } else {
                t = nums[i];
            }
            if(t > sum) {
                sum = t;
            }
        }
        return sum;
    }
};