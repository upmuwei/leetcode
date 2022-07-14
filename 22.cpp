#include <iostream>
#include <vector>

using namespace std;

//时间或者空间不够的时候想想怎么优化
int main()
{
    int dividend = -2147483648, divisor = 2;
    bool negative = false;
        bool sign = false;
        if((dividend|divisor) < 0) {
            negative = true;
        }
        if(dividend < 0 && divisor < 0) {
            negative = false;
        }
        int n = 0;
        if(dividend == 0x80000000 && divisor == -1) {
            return 0x7fffffff;
        } else if(dividend == 0x80000000 && divisor == 1) {
            return 0x80000000;
        } else if(dividend == 0x80000000 && divisor == 0x80000000 ) {
            return 1;
        } else if(divisor == 0x80000000) {
            return 0;
        } else if(dividend == 0x80000000) {
            dividend = 0x7fffffff;
            sign = true;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        if(sign) {
            n++;
            dividend -= divisor;
            dividend ++;
        }
        while(dividend >= divisor) {
            int t = divisor;
            int p = 1;
            dividend -= divisor;
            n++;
            t = t << 1;
            while(dividend >= t && t > 0) {
                dividend -= t;
                p = p << 1;
                n += p;
                t = t << 1;
            }
        }
        
    cout << (negative?-n:n) << endl;
    
}