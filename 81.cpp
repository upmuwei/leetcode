class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(target >= nums[0]) {
            int i = 0;
            int length = nums.size();
            while(i < length && nums[i] < target) {
                i++;
            }
            if(i == length) {
                return false;
            }
            return target == nums[i] ? true : false;
        } else {
            int j = nums.size() - 1;
            int t = nums[j];
            while(j>=0 &&nums[j] > target) {
                if(t < nums[j]) {
                    break;
                }
                j--;
            }
            if(j < 0) {
                return false;
            }
            return nums[j] == target ? true : false;
        } 
    }
};