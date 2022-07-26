class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(s[i] == ' ')
            i--;
        int t = i;
        for(; i >= 0; i--) {
            if(s[i] == ' ') {
                break;
            }
        }
        return t - i;
    }
};