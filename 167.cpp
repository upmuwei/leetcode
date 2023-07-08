class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++) {
            for(int j = numbers.size() - 1; j > i; j--) {
                int t = numbers[i] + numbers[j];
                if(t == target) {
                    return {i + 1, j + 1};
                } else if(t < target) {
                    break;
                }
            }
        }
        return {0, 0};
    }
};