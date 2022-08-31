class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int num = rowIndex + 1;
        vector<int> result(num, 1);
        int t = 1;
        for(int i = 2; i < num; i++) {
            t = 1;
            for(int j = 1; j < i; j++) {
                int tmp = result[j];
                result[j] = t + result[j];
                t = tmp;
            }
        }
        return result;
    }
};