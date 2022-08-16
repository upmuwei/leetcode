class Solution {
public:
    int tribonacci(int n) {
        int p[n+1];
        p[0] = 0;
        if(n == 0) {
            return 0;
        }
        if(n == 1 || n== 2) {
            return 1;
        }
        p[1] = p[2] = 1;
        for(int i = 3; i <=n; i++) {
            p[i] = p[i-1] + p[i-2] + p[i-3];
        }
        return p[n];
    }
};