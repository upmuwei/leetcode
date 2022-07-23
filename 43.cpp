#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    Solution(){}

    string multiply(string num1, string num2) { 
        if(num1[0] == '0' || num2[0] == '0') {
            return "0";
        }
        unsigned long long i;
        int j;
        i = to_Integer(num1);
        string s;
        unsigned long long tmp = 0;
        for(j = num2.size() -1; j>=0; j--) {
            tmp = i * (num2[j] - '0');
            cout << tmp << endl;
            int t = tmp%10;
            s.insert(s.begin(), t + '0');
            tmp /= 10;
        }
        
        if(tmp) {
            return to_string(tmp) + s;
        } else {
            return s;
        }
        
    }

    unsigned long long to_Integer(string num) {
        unsigned long long carry = 10;
        unsigned long long result = 0;
        for(auto c : num) {
            result = carry * result + c - '0';
        }
        return result;
    }
};


int main()
 {
    string num1 = "3866762897776739956";
    string num2 = "15975363164662";
    Solution solution;
    string s = solution.multiply(num1, num2);
    cout << s << endl;
    return 0;
 }