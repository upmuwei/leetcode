class Solution {
public:
    int fib(int n) {
        if(n == 0) {
            return 0;
        }
        int x[n + 1];
        x[0] = 0, x[1] = 1;
        for(int i = 2; i<=n; i++) {
            x[i] = x[i-1] + x[i-2];
        }
        return x[n];
    }
};