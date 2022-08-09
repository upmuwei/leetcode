class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        int low = 0, high = length - 1;
        while(low < high) {
            while(low < length && nums[low] != 2) {low++;}
            while(high >= 0 && nums[high] == 2) {high--;}
            if(low < high) {
                swap(nums[low], nums[high]);
                low++;
                high--;
            }
        }
        low = 0;
        while(low < high) {
            while(low < length && nums[low] == 0) {low++;}
            while(high >= 0 && nums[high] >= 1) {high--;}
            if(low < high) {
                swap(nums[low], nums[high]);
                low++;
                high--;
            }
        }
    }
};