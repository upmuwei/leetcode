class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                count++;
                while(s[i] == '1') {    
                    i++;
                    if(i == s.size()) {
                        break;
                    }
                }
            }
            
        }
        return (count < 2);
    }
};