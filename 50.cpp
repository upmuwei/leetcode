class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) {
            return 1;
        }
        if(x == -1) {
            if(n % 2 == 0)
                return 1;
            return -1;
        }
        if(n == 0) {
            return 1;
        }
        if((x > 1 || x < -1)&& n < -0xfffffff) {
            return 0;
        }
        int negative = true;
        if(n > 0) {
            negative = false;
        }
        long t = abs(n);
        double result = x;
        double result2 = 1;
        while(t > 0) {
            result = x;
            int i = 1;
            while(i <( t/2)) {
                result *= result;
                i += i;
            }
            result2 *= result;
            t -= i;
        }
        
        
        return negative? 1/result2 : result2;
    }
};