class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;
        vector<string> t(n, string(n, '.'));
        vector<bool> looked(n, false);
        seek(sum, t, looked, 0, n);
        return sum;
    }

    void seek(int& sum, vector<string>& t,  vector<bool>& looked, int index, int n) {
        if(index == n) {
            sum++;
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!looked[i]) {
                bool sign = false;
                for(int j = 1; j <= index; j++) {
                    if(i-j>=0&&t[index - j][i - j] == 'Q') {
                        sign = true;
                        break;
                    }
                    if(i+j<n&&t[index - j][i + j] == 'Q') {
                        sign = true;
                        break;
                    }
                }
                if(sign) {
                    continue;
                }
                t[index][i] = 'Q';
                looked[i] = true;
                seek(sum, t, looked, index +1, n);
                looked[i] = false;
                t[index][i] = '.';
            }
        }
    }
};