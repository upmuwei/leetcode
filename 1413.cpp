class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min = 0, sum = 0;
        for(auto t : nums) {
            sum += t;
            if(sum < min) {
                min = sum;
            }
        }
        return 1 - min;
    }
};