class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;
        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >='0' && s[i] <= '9')) {
                v.push_back(s[i]);
            } else if(s[i] >= 'A' && s[i] <= 'Z') {
                v.push_back(s[i] - 'A' + 'a');
            }
        }
        if(v.size() <= 1) {
            return true;
        }
        int middle = v.size() / 2;
        for(int i = 0; i < middle; i++) {
            if(v[i] != v[v.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};