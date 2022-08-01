class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        bool sign[10000] = {false};
        vector<string> s(strs);
        for(int i = 0; i< strs.size(); i++) {
            sort(s[i].begin(), s[i].end());
        }
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i++) {
            if(sign[i]) {
                continue;
            }
            sign[i] = true;
            vector<string> t;
            t.push_back(strs[i]);
            for(int j = i + 1; j < strs.size(); j++) {
                if(sign[j]) {
                    continue;
                }
                // cout << s[j] << " " << s[i] << endl;
                if(s[j] == s[i]) {
                    sign[j] = true;
                    // cout << strs[i] << " " << strs[j] << endl;
                    t.push_back(strs[j]);
                }
            }
            result.push_back(t);
        }
        return result;
    }
};