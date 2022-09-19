class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max = 0, maxIndex = -1, second = 0, secondIndex = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(maxIndex == -1) {
                maxIndex = nums[i];
                max = 1;
            } else if(maxIndex == nums[i]) {
                max++;
            } else if(secondIndex == -1) {
                secondIndex = nums[i];
                second = 1;
            } else if(secondIndex == nums[i]) {
                second++;
                if(second >= max) {
                    swap(second, max);
                    swap(secondIndex, maxIndex);
                }
            } else {
                secondIndex = nums[i];
                second = 1;
            }
        }
        return maxIndex;
    }
};