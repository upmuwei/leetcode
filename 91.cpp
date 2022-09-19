class Solution {
public:
    int numDecodings(string s) {
        int *p = new int[s.size() + 1]();
        p[0] = 1;
        if(s[0] != '0') {
            p[1] = 1;
        }
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != '0'&&s[i-1] != '0') {
                if(s[i-1] > '2') {
                    p[i + 1] = p[i];
                } else if(s[i - 1] == '2' && s[i] > '6'){
                    p[i + 1] = p[i];
                } else {
                    p[i+1] = p[i] + p[i-1];
                }
            } else if(s[i]  == '0'){
                if((s[i-1] > '2') || (s[i-1] == '0')) {
                    return 0;
                }
                p[i + 1] = p[i - 1];
            } else {
                p[i + 1] = p[i];
            }
            
        }
        int result = p[s.size()];
        delete[] p;
        return result;
    }
};