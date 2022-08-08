class Solution {
public:
    string addStrings(string num1, string num2) {
        int t = (num1.size() > num2.size()?num1.size() :num2.size()) + 1; 
        vector<int> num(t, 0);
        int i = num1.size() - 1, j = num2.size() - 1;
        t--;
        while(i>=0&&j>=0) {
            num[t] += num1[i] + num2[j] - '0' - '0';
            num[t-1] += num[t] / 10;
            num[t] %= 10;
            i--;
            j--;
            t--;
        }
        while(i>=0) {
            num[t] += num1[i] - '0';
            num[t-1] += num[t] / 10;
            num[t] %= 10;
            i--;
            t--;
        }
        while(j>=0) {
            num[t] += num2[j] - '0';
            num[t-1] += num[t] / 10;
            num[t] %= 10;
            j--;
            t--;
        }
        string result;
        if(num[t] == 0) {
            t++;
        }
        while(t < num.size()) {
            result.push_back(num[t++] +' 0');
        }
        return result;
    }
};