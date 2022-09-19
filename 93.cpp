class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.size() < 4) {
            return result;
        }
        int firstLength = s.size() - 3, secondLength = s.size() - 2, thirdLength = s.size() - 1;
        for(int i = 0; i < 3 && i < firstLength; i++) {
            if(s[0] == '0'&& i > 0) {
                break;
            }
            string t1 = s.substr(0, i + 1);
            if(stoi(t1) > 255) {
                continue;
            }
            t1 += '.';
            for(int j = i + 1; j <= i + 3 && j < secondLength; j++) {
                if(s[i + 1] == '0'&& j > i + 1) {
                    break;
                } 
                if(stoi(s.substr(i + 1, j - i)) > 255) {
                    continue;
                }
                string t2 = t1 +  s.substr(i + 1, j - i) + '.';
                for(int k = j + 1; k <= j + 3 && k < thirdLength; k++) {
                    if(s[j + 1] == '0'&& k > j + 1) {
                        break;
                    } 
                    if(stoi(s.substr(j + 1, k - j)) > 255) {
                        continue;
                    }
                    string t3 = t2 + s.substr(j + 1, k - j) + '.';
                    if((s.size() - k - 1 > 3) ||(s[k + 1] == '0'&& s.size() > (k + 2))) {
                        continue;
                    }
                    if(stoi(s.substr(k + 1, s.size() - k - 1)) > 255) {
                        continue;
                    }
                    t3 += s.substr(k + 1, s.size() - k - 1);
                    result.push_back(t3);
                }
            }
        }
        return result;
    }

    
};