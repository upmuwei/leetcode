class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        for(int i = 0; i < logs.size(); i++) {
            string t = logs[i];
            if(t[0] != '.') {
                step++;
            } else if(t[1] == '.' && step > 0) {
                step--;
            }
        }
        return step;
    }
}; 