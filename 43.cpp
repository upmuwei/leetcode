#include <iostream>
#include <vector>
#include <string>

using namespace std;
//使用数组对整数进行存储
class Solution {
public:
    string multiply(string num1, string num2) { 
        if(num1[0] == '0'|| num2[0] == '0') {
            return "0";
        }
        vector<int> num(num1.size() + num2.size(), 0);
        for(int i = num1.size() - 1; i >= 0; i--) {
            for(int j = num2.size() - 1; j >= 0; j--) {
                num[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
                num[i + j ] += num[i+j+1] /10;
                num[i+ j + 1] %= 10;
            }
        }
        string result;
        bool begin = false;
        for(auto t : num) {
            if(t == 0&&!begin) {
                continue;
            } else{
               begin = true; 
            }
            result.push_back(t + '0');
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