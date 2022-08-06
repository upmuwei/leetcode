class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), standard);
        vector<string> result;
        for(int i = 0; i < words.size() - 1; i++) {
            for(int j = i + 1; j < words.size(); j++) {
                int t = words[j].find(words[i]);
               // cout << t << endl;
                if(t != -1) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
    static bool standard(string a, string b) {
        return a.size() < b.size();
    }
};