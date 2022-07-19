class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low =0, middle;
        while(low <= high) {
            middle = (low + high) / 2;
            if(nums[middle] == target) {
                return middle;
            } else if(nums[middle] > target){
                high = middle -1;
            } else {
                low = middle + 1;
            }
        }
        return -1;
    }
};