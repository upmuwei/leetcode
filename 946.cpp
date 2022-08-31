class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int index = 0;
        vector<int> sta;
        // sta.push_back(pushed[0]);
        for(int i = 0; i < pushed.size(); i++) {
            if(pushed[i] == popped[index]) {
                index++;
            } else {
                if(sta.size()) {
                    int t = sta.back();
                    if(t == popped[index]) {
                        sta.pop_back();
                        index++;
                        i--;
                    } else {
                        sta.push_back(pushed[i]);
                    }
                } else {
                    sta.push_back(pushed[i]);
                }
                
            }
        }
        while(sta.size()) {
            int t = sta.back();
            if(t != popped[index]) {
                return false;
            }
            index++;
            sta.pop_back();
        }
        return true;
    }
};