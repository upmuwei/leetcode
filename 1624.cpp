class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max = -1;
        vector<int> indexs(26, -1);
        for(int i = 0; i < s.size(); i++) {
            if(indexs[s[i] - 'a'] == -1) {
                indexs[s[i] - 'a'] = i;
            } else {
                int t = i - indexs[s[i] - 'a'] - 1;
                if(t > max) {
                    max = t;
                }
            }
        }
        return max;
    }
};