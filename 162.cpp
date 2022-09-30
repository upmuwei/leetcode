class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int middle = (low +high) / 2;
            if(middle-1>=0 &&nums[middle] > nums[middle - 1] && nums[middle] > nums[middle +1]) {
                return middle;
            } else if(middle + 1 < nums.size() && nums[middle] < nums[middle +1]) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return low;
    }
};