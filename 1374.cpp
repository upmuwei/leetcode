class Solution {
public:
    string generateTheString(int n) {
        if(n == 1) {
            return "c";
        }
        string t;
        if(n%2 == 0) {
            int i = n / 2;
            if(i % 2 == 0) {
                for(int j = 0; j< i + 1; j++) {
                    t.push_back('a');
                }
                for(int j = 0; j< i - 1; j++) {
                    t.push_back('b');
                }
            }
            else {
                for(int j = 0; j< i; j++) {
                    t.push_back('a');
                }
                for(int j = 0; j< i; j++) {
                    t.push_back('b');
                }
            }
        }
        else {
            t.push_back('c');
            int i = n / 2;
           if(i % 2 == 0) {
                for(int j = 0; j< i + 1; j++) {
                    t.push_back('a');
                }
                for(int j = 0; j< i - 1; j++) {
                    t.push_back('b');
                }
            }
            else {
                for(int j = 0; j< i; j++) {
                    t.push_back('a');
                }
                for(int j = 0; j< i; j++) {
                    t.push_back('b');
                }
            }
        }
        return t;
    }
};