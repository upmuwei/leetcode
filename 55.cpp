class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() < 2) {
            return true;
        }
        for(int i = 0; i  < nums.size(); i++) {
            if(nums[i] == 0) {
                int k = 1;
                int j;
                for(j = i - 1; j >= 0; j--) {
                    if(nums[j] > k) {
                        break;
                    }
                    k++;
                }
                if(i!= (nums.size() - 1) &&j < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};