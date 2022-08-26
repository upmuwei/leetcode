class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = 1, secMax = 1;
        for(auto num : nums) {
            if(num > max) {
                if(max > secMax) {
                    secMax = max;
                }
                max = num;
            } else if(num > secMax) {
                secMax = num;
            }
        }
        return (max - 1) * (secMax - 1);
    }
};