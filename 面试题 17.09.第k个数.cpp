class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> res(k, 0);
        res[0] = 1;
        int p3 = 0, p5 = 0, p7 = 0;
        for(int i = 1; i < k; i++) {
            int result = min(res[p3] * 3, min(res[p5] * 5, res[p7] * 7));
            if(result % 3 == 0) {
                p3++;
            }
            if(result % 5 == 0) {
                p5++;
            }
            if(result % 7 == 0) {
                p7++;
            }
            res[i] = result;
        }
        return res[k - 1];
    }
};