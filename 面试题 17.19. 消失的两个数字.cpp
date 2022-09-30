class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        nums.push_back(0);
        nums.push_back(0);
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            while(i != nums[i] - 1&&nums[i] - 1>=0) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i != nums[i] - 1) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};