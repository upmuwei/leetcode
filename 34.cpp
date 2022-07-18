class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, middle;
        while(i <= j) {
            middle = (i + j) / 2;
            if(nums[middle] > target) {
                j = middle -1;
            } else if(nums[middle] == target) {
                break;
            } else {
                i = middle + 1;
            }
        }
        vector<int> arrange;
        if(i > j) {
            arrange.push_back(-1);
            arrange.push_back(-1);
        } else {
            int t = middle + 1;
            while(t< nums.size() && nums[t] == target) {
                t++;
            }
            while((--middle >= 0) && nums[middle] == target);
            arrange.push_back(middle + 1);
            arrange.push_back(t - 1);
        }
        return arrange;
    }
};