#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int t = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            t += (digits[i]);
            if(t < 10) {
                digits[i] = t;
                t = 0;
                break;
            } else {
                digits[i] = 0;
                t = 1;
            }
        }
        if(t == 1) {
            digits.insert(digits.begin(), t);
        }
        return digits;
    } 
};