class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> match;
        vector<string> result;
        for(auto s: cpdomains) {
            deal(match, s);
        }
        for (auto it = match.begin(); it != match.end(); ++it)  {
            string s = to_string(it->second) + ' ' + it->first;
            result.push_back(s);
        }
        return result;
    }

    void deal(map<string, int>& match, string& s) {
        int i = 0;
        int num = 0;
        for(; i < s.size(); i++) {
            if(s[i] == ' ') {
                num = stoi(s.substr(0, i));
                match[s.substr(i + 1, s.size() - i-1)] += num;
                break; 
            }
        }
        for(i++; i < s.size(); i++) {
            if(s[i] == '.') {
                match[s.substr(i + 1, s.size() - i-1)] += num;
            }
        }
    }
};