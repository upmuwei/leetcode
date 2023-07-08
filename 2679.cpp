class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int count = nums[0].size();
        int sum = 0, max = 0;
        while(count) {
            max = 0;
            for(int i = 0; i < nums.size(); i++) {
                int t = 0;  
                for(int j = 0; j < nums[i].size(); j++) {
                    if(nums[i][j] > nums[i][t]) {
                        t = j;
                    }
                }
                if(nums[i][t] > max) {
                    max = nums[i][t];
                }
                nums[i].erase(nums[i].begin() + t);
            }
            sum += max;
            count--;
        }   
        return sum;
    }

    int matrixSum2(vector<vector<int>>& nums) {
        
        int sum = 0, max = 0;
        for(int i = 0; i < nums.size(); i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        for(int j = 0; j < nums[0].size(); j++) {
            max = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i][j] > max) {
                    max = nums[i][j];
                }
            }
            sum += max;
        }
        return sum;
    }
};
