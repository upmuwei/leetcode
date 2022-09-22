class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = 1; i <= n; i++) {
            if(s.find(toString(i)) == -1) {
                return false;
            }
        }
        return true;
    }

    string toString(int k) {
        string t;
        vector<char> p;
        while(k) {
            p.push_back(k%2 + '0');
            k /= 2;
        }
        while(p.size()) {
            t.push_back(p.back());
            p.pop_back();
        }
        return t;
    }
};