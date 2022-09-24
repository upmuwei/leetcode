class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        for(int i = 0; i < code.size(); i++) {
            if(k > 0) {
                for(int j = i + 1; j <= i + k; j++) {
                    result[i] += code[j%code.size()];
                }
            }
            else if(k < 0) {
                for(int j = i - 1; j >= i + k; j--) {
                    result[i] += code[(j +code.size()) % code.size()];
                }
            } else {
                result[i] = 0;
            }
        }
        return result;
    }
};