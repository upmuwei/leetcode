class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int max = 0, index = 1900;
        for(int i = 0; i <= 100; i++) {
            int t = 0;
            int year = 1900 + i;
            for(int j = 0; j < birth.size(); j++) {
                if(year >= birth[j] && year <= death[j]) {
                    t++;
                }
            }
            if(t > max) {
                max = t;
                index = year;
            }
        }
        return index;
    }
};