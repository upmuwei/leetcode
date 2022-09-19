class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return a > b;
        });
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= count) {
                if(count == nums[i]) {
                    return - 1;
                }
                break;
            }
            count++;
        }
        return (count == 0 ? -1 : count);
    }
};