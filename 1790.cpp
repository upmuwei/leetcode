class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0, index = -1;
        for(int i = 0; i < s1.size(); i++) {
            if(count == 0 && s1[i] != s2[i]) {
                index = i;
                count++;
            } else if(s1[i] != s2[i]) {
                swap(s1[i], s1[index]);
                if(s1 != s2) {
                    return false;
                }
                return true;
            }
        }
        return (count == 0 ? true : false);
    }
};