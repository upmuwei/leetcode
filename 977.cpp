class Solution {
public:
    //可以用双指针解决这个问题，先找到最大的
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        vector<int> minus;
        while(i<nums.size() && nums[i] < 0) {
            minus.push_back(nums[i] * nums[i]);
            i++;
        }
        vector<int> result;
        int j = minus.size() - 1;
        while(i< nums.size() && j >=0) {
            int t = nums[i] * nums[i];
            if(t < minus[j]) {
                result.push_back(t);
                i++;
            }else {
                result.push_back(minus[j]);
                j--;
            }
        }
        while(i < nums.size()) {
            result.push_back(nums[i] * nums[i]);
            i++;
        }
        while(j >= 0) {
            result.push_back(minus[j]);
            j--;
        }
        return result;
    }
};