class Solution {
public:
//细心， 看范围，找规律，想算法
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size() == 1) {
            return 0;
        }
        int max = 0;
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        int factor = 0;
        for(int j = 0; j < nums.size(); j++, factor++) {
            max += nums[j] * factor;
        }
        int t = max;
        for(int i = 1; i < nums.size(); i++) {
           t += sum - nums.size() * nums[nums.size() - i];
           if(t > max) {
               max = t;
           }
        }
        return max;
    }
};