class Solution {
public:
    string reformatNumber(string number) {
        vector<char> n;
        for(int i = 0; i < number.size(); i++) {
            if(number[i] >= '0' && number[i] <= '9') {
                n.push_back(number[i]);
            }
        }
        string result;
        int length = n.size() / 3;
        int i = 0;
        for(; i < 3 * length; i += 3) {
            result.push_back(n[i]);
            result.push_back(n[i + 1]);
            result.push_back(n[i + 2]);
            result.push_back('-');
        }
        if(i + 1 == n.size()) {
            result.pop_back();
            result.insert(result.size() - 1, "-");
            result.push_back(n[i]);
        } else if(i + 2 == n.size()) {
            result.push_back(n[i]);
            result.push_back(n[i +1]);
        } else {
            result.pop_back();
        }
        return result;
    }
};