
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> t;
        divide(result, s, 0, t);
        return result;
    }

    void divide(vector<vector<string>>& result, string& s, int begin, vector<string>& t) {
        if(begin == s.size()) {
            result.push_back(t);
            return;
        }
        for(int i = begin + 1; i <= s.size(); i++) {
            if(isPalindrome(s, begin, i - begin)) {
                t.push_back(s.substr(begin, i-begin));
                divide(result, s, i, t);
                t.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int begin, int length) {
        if(length == 1) {
            return true;
        }
        int end = begin + length/2;
        for(int i = begin; i < end; i++) {
            if(s[i] != s[length + 2*begin - i-1]) {
                return false;
            }
        }
        return true;
    }
};