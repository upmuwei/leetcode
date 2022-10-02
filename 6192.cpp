class Solution {
public:
    int commonFactors(int a, int b) {
        int min = (a > b ? b : a);
        int length = min / 2;
        int count = 0;
        for(int i = 1; i <= length; i++) {
            if(a%i==0&&b%i==0) {
                count++;
            }
        }
        if(a%min==0&&b%min==0) {
            count++;
        }
        return count;
    }
};