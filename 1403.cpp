class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums;
        }
        int sign = true;
        vector<int> result;
        int all = 0;
        int t = 0;
        for(auto i : nums) {
            all += i;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        int min = 0, max = nums.size() - 1;
        while(all > t&&min<=max) {
            if(nums[min] < nums[max]) {
                t += nums[min];
                all -= nums[min];
                min++;
                sign = false;
            } else {
                t += nums[max];
                all -= nums[max];
                max--;
                sign = true;
            }
        }
        if(sign) {
            max++;
        } else {
            min--;
        }
        for(int i = min; i <= max; i++) {
            result.push_back(nums[i]);
        }
        return result;
    }
};