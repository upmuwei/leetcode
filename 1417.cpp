class Solution {
public:
    string reformat(string s) {
        vector<char> digits, letters;
        for(auto c : s) {
            if(c>= '0' && c <= '9') {
                digits.push_back(c);
            }else {
                letters.push_back(c);
            }
        }
        string result;
        int len1 = digits.size(), len2 = letters.size();
        if(len1 > len2+1 || len2 > len1 + 1) {
            return result;
        }
        if(len1 > len2) {
            for(int i = 0; i < len2; i++) {
                result.push_back(digits[i]);
                result.push_back(letters[i]);
            }
            result.push_back(digits[len1 - 1]);
        }else {
            for(int i = 0; i < len1; i++) {
                result.push_back(letters[i]);
                result.push_back(digits[i]);
            }
            if(len2 > len1) {
                result.push_back(letters[len2 - 1]);
            }
        }
        return result;
    }
};