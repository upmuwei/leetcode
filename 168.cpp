class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while(columnNumber) {
            if(columnNumber %26 == 0) {
                result.insert(result.begin(), 26 + 'A' - 1);
                columnNumber = columnNumber/26 - 1;
            } else {
                result.insert(result.begin(), columnNumber%26 + 'A' - 1);
                columnNumber /= 26;
            }
            

        }
        return result;
    }
};