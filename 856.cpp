class Solution {
public:
    int scoreOfParentheses(string s) {
        int i = 0;
        int k = 0;
        int sum = 0;
        while(i != s.size()) {
            sum += match(s, i, k);
        }
        return sum;
    }

    int match(string s, int& i, int &k) {
        if(i == s.size()) {
            return 0;
        }
        if(s[i] == ')') {
            i++;
            k--;
            return 0;
        }
        if(s[i] == '('&&s[++i] != ')') {
            k++;
            int t =  2 * match(s, i, k);
            if(k != 0) {
                return t + match(s, i, k);
            }
            return t;
        } else {
            return 1 + match(s, ++i, k);
        }
    }
};