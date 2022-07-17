class Solution {
public:
    int search(vector<int>& nums, int target) {
        int t = nums[0], index = 0;
        if(target >= nums[0]) {
            while(index < nums.size()) {
                if(target > nums[index]) {
                    index ++;
                } else if(target == nums[index]) {
                    return index;
                } else {
                    return -1;
                }
            }  
        } else {
            index = nums.size() - 1;
            while(index >= 0) {
                if(target < nums[index]) {
                    index --;
                } else if(target == nums[index]) {
                    return index;
                } else {
                    return -1;
                }
            }
        }
        return -1;
    }
};