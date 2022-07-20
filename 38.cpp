class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        string s = countAndSay(n-1);
        string result;
        int count = 1;
        char c;
        for(int i = 0; i < s.size();) {
            c = s[i];
            i++;
            while(i< s.size() && s[i] == c) {
                count++;
                i++;
            }
            result.append(to_string(count));
            result.push_back(c);
            count = 1;
        }
        return result;
    }
};