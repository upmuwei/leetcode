class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> hashChar;
        int max = 0;
        int index = -1;
        for(int i = 0; i < s.size(); i++) {
            if(hashChar[s[i]] == 0) {
                if(index == -1) {
                    index = i;
                }
                hashChar[s[i]] = i + 1;
            }else {
                int right = hashChar[s[i]] - 1;
                for(int j = index; j < right; j++) {
                    hashChar[s[j]] = 0;
                }
                index = hashChar[s[i]];
                hashChar[s[i]] = i + 1;
                
            }         
            if(i - index + 1 > max) {
                max = i -index + 1;
            }
        }
        return max;
    }
};