class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) {
            return 0;
        }
        int walk = 0;
        for(int i = 0; i < nums.size(); ) {
            int t = nums[i];
        
            walk++;
            if((i + t) >= (nums.size() -1)) {
                    return walk;
            }
            int index = 1;
            for(int j = 2; j <= t; j++) {
                if(nums[i + j] != 0 && (nums[j + i] + j) >= (nums[index + i] + index)) {
                    index = j;
                }
            }
            i += index;
          
        }
        return walk;
    }
};