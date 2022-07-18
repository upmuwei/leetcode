class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> c, index;
        int length = s.size(), count = 0, max = 0;
        c.push_back(-1);
        index.push_back(-1);
        for(int i = 0; i < length; i++) {
            if(s[i] == '(') {
                c.push_back(i);
                index.push_back(count);
            }
            else {
                if(c.back() >= 0 && s[c.back()] == '(') {
                    c.pop_back();
                    index.pop_back();
                    count += 2;
                } else {
                    if(count > max) {
                        max = count;
                    }
                    count = 0;
                }
            }
        }
        while(c.back() != -1) {
            int t = count - index.back();
            if(t > max) {
                max = t;
            }
            count = index.back();
            c.pop_back();
            index.pop_back();
        }
        if(count > max) {
            max = count;
        }
        return max;
    }
};