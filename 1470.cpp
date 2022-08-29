class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(nums.size());
        int i = 0, j = n, m = nums.size();
        while(i < n&&j < m) {
            result[2 * i] = nums[i];
            result[2 * i + 1] = nums[j];
            i++;
            j++;
        }
        // int t = 2 * (m - n);
        // while(i<n) {
        //     result[t++] = nums[i++];
        // }
        // t = 2 * i;
        // while(j < m) {
        //     result[t++] = nums[j++];
        // }
        return result;
    }
};