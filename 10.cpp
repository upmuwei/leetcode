class Solution {
public:
    bool isMatch(string s, string p) {
       return match(s, p, 0, 0);
    }   

    bool match(string& s, string& p, int i, int j) {
        if(i >= s.size() && j >= p.size()) {
            return true;
        }
        if(j >= p.size()) {
            return false;
        }
        if(i >= s.size()) {
            while(j < p.size()) {
                if(p[j] == '*') {
                    j++;
                }
                else if(j < (p.size() - 1) && p[j + 1] == '*') {
                    j += 2;
                } else {
                    return false;
                }
            }
            return true;
        }
        if(s[i] == p[j] || p[j] == '.') {
            if(j < (p.size() - 1) && p[j + 1] == '*') {
                return match(s, p, i, j + 2) || match(s, p, i + 1, j);
            } else {
                return match(s, p, i + 1, j + 1);
            }
        } else {
            if(j < (p.size() - 1) && p[j + 1] == '*') {
                return match(s, p, i, j + 2);
            }
            return false;
        }
    }
};