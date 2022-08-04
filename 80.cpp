class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int elementLength = 0, t = 10001;
        for(int i = 0; i < nums.size(); i++) {
            if(t == nums[i]) {
                if(elementLength < 2) {
                    elementLength++;
                }
                else {
                    nums.erase(nums.begin() + i);
                    i--;
                }
            } else {
                elementLength = 1;
                t = nums[i];
            }
        }    
        return nums.size();
    }
};