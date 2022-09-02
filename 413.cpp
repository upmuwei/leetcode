class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) {
            return 0;
        }
        int count = 0;
        int add = 1;
        int sum = 0;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] - nums[i-1] == nums[i -1] - nums[i -2]) {
                count += add;
                add++;
            } else {
                if(count != 0) {
                    sum += count;
                    count = 0;
                    add = 1;
                }
            }
        }
        if(count != 0) {
            sum += count;
        }
        return sum;
    }
};