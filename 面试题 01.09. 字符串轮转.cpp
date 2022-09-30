class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        if(s1.size() == 0) {
            return true;
        }
        for(int i = 0; i<s1.size(); i++) {
            if(s1[i] == s2[0]) {
                if(s1.substr(i,s1.size() - i) == s2.substr(0, s1.size() - i) && s1.substr(0, i) == s2.substr(s1.size() - i, i)) {
                    return true;
                }
            }
        }
        return false;
    }
};