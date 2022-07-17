class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size() - 1;
        while(--length >= 0) {
            if(nums[length] < nums[length + 1]) {
                break;
            }
        }
        if(length < 0) {
            sort(nums.begin(), nums.end());
        } else {
            int t = nums[length], i = length, min = 1000, k;
            while(i < nums.size()) {
                if(nums[i] > t && nums[i] < min) {
                    k = i;
                    min = nums[i];
                }
                i++;
            }
            nums[length] = nums[k];
            nums[k] = t;
            sort(nums.begin() + length +1, nums.end());
        } 
    }
};