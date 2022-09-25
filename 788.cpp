class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 2; i <= n; i++) {
            int t = i;
            int sign = false;
            while(t) {
                int digit = t%10;
                if(digit == 2 || digit == 5||  digit == 6 || digit == 9) {
                    sign = true;
                } else if(digit == 3 || digit == 4 || digit == 7) {
                    sign = false;
                    break;
                }
                t /= 10;
            }
            if(sign) {
                count++;
            }
        }
        return count;
    }
};