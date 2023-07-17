class Solution {
public:
    int alternateDigitSum(int n) {
        int reuslt = 0;
        int minus = 1;
        while(n) {
            reuslt += minus * (n % 10);
            n /= 10;
            minus *= -1; 
        }
        if(minus == 1) {
            return reuslt * (-1);
        }
        return reuslt;
    }
};