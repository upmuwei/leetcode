class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> s;
        int count = 0;
        int index = -1;
        for(int i = 0; i < text.size(); i++) {
            if(text[i] == ' ') {
                count++;
                if(index != - 1) {
                    s.push_back(text.substr(index, i - index));
                    index = -1;
                }
            } else {
                if(index == - 1) {
                    index = i;
                }
            }
        }
        if(index != -1) {
            s.push_back(text.substr(index, text.size() - index));
        }
        
        string result;
        if(s.size() == 1) {
            result = s[0];
            for(int i = 0; i < count; i++) {
                result += ' ';
            }
            return result;
        }
        int space = count / (s.size() - 1);
        for(int i = 0; i < s.size() - 1; i++) {
            result += s[i];
            for(int j = 0; j < space; j++) {
                result += ' ';
            }
        }
        result += s[s.size() - 1];
        int t = count %(s.size() - 1);
        for(int j = 0; j < t; j++) {
            result += ' ';
        }
        return result;
    }
};