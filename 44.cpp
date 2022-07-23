#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }

    bool match(string& s, string& p, int i, int j) {
        if(i == s.size() && j == p.size()) {
            return true;
        }
        if(i == s.size() && p[j] == '*') {
            cout << i << " " << j << " " << p[j] << endl;
            j++;
            while(j != p.size() && p[j] == '*') {
                j++;
            }
            if(j == p.size()) {
                return true;
            }
            return false;
        }
        if(i == s.size() || j == p.size()) {
            return false;
        }
        if(s[i] == p[j]) {
            return match(s, p, i + 1, j + 1);
        } else if(p[j] == '?') {
            return match(s,p, i + 1, j + 1);
        } else if(p[j] == '*') {
            bool sign = match(s, p, i + 1, j);
            if(sign) {
                return true;
            }
            cout << i << " " << j << endl;
            return match(s, p, i, ++j);
        }
        return false;
    }
};
int main() {
    Solution solution;
    string s = "adceb", p = "*a*b";
    cout << solution.isMatch(s, p) << endl;
    return 0;
}