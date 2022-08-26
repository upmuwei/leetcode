class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int max = 0;
        int positiveCount = 0, negativeCount = 0, first = 0, index, lastIndex;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                positiveCount++;
            } else if(nums[i] == 0){
                first = 0;
                if(negativeCount % 2 == 0) {
                    positiveCount += negativeCount;
                } else {
                    int t1 = i - index - 1;
                    int t2 =  lastIndex - i + negativeCount  + positiveCount;
                    positiveCount = (t1 > t2? t1 :t2);
                }
                if(positiveCount > max) {
                    max = positiveCount;
                }
                negativeCount = 0;
                positiveCount = 0;
            } else {
                if(!first) {
                    if(positiveCount > max) {
                        max = positiveCount;
                    }
                    first = 1;
                    index = i;
                }
                lastIndex = i;
                negativeCount++;
            }
        }
        if(negativeCount % 2 == 0) {
            positiveCount += negativeCount;
        } else {
            int t1 = nums.size() - index - 1;
            int t2 =  lastIndex - nums.size() + negativeCount  + positiveCount;
            positiveCount = (t1 > t2? t1 :t2);
        }
        if(positiveCount > max) {
            max = positiveCount;
        }
        return max;
    }
};

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int max = 0;
        int positiveCount = 0, negativeCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                positiveCount++;
                if(negativeCount > 0) {
                    negativeCount++;
                }
            } else if(nums[i] == 0){
                negativeCount = 0;
                positiveCount = 0;
            } else {
                if(positiveCount == 0 && negativeCount == 0) {
                    negativeCount++;
                } else if(positiveCount > 0 && negativeCount == 0) {
                    negativeCount = positiveCount + 1;
                    positiveCount = 0;
                } else if(positiveCount == 0 && negativeCount > 0) {
                    positiveCount = negativeCount +1;
                    negativeCount = 1;
                } else if(positiveCount > 0 && negativeCount > 0) {
                    int t = negativeCount;
                    negativeCount = positiveCount + 1;
                    positiveCount = t + 1;
                }
            }
            if(positiveCount > max) {
                max = positiveCount;
            }
        }
        return max;
    }
};