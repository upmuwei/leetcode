class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> nums(n +1);
        nums[0] = 1;
        for(int i = 1; i <= n; i ++) {
            int result = 9;
            int j = i - 1;
            int t = 9;
            while(j--) {
                result *= t;
                t--; 
            }
            nums[i] = nums[i - 1] + result;
        }
        return nums[n];
    }
};