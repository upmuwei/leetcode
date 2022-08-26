class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = -10, t, negativeIndex = 0, negative = false, negativeCount = 0;
        int j = 1;
        vector<int> negativeIndexs;
        negativeIndexs.push_back(0);
        while(negativeIndexs.size()) {
            t = 1;
            negativeIndex = negativeIndexs.back();
            negativeIndexs.pop_back();
            for(int i = negativeIndex; i < nums.size(); i++) {
            t *= nums[i];
            if(t > max) {
                max = t;
            }
            if(nums[i] == 0) {
                if(j > 1) {
                    break;
                }
                t = 1;
                if(negativeCount %2 == 0&&negativeCount > 0) {
                    negativeIndexs.pop_back();
                }
                negativeCount = 0;
                negative = false;
            } else if(nums[i] < 0) {
                if(!negative) {
                    negativeIndexs.push_back(i + 1);
                    negative = true;
                }
                negativeCount++;
            }
            }
            // if(negativeCount%2 == 0) {
            //     break;
            // }
            j++;
        }
             
        return max;
    }
};