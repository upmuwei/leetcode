class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for(int i = 0; i < arr.size();) {
            int t = i;
            for(int j = 0; j < pieces.size(); j++) {
                if(pieces[j][0] == arr[i]) {
                    t++;
                    for(int k = 1; k < pieces[j].size(); k++) {
                        if(pieces[j][k] != arr[t]) {
                            return false;
                        }
                        t++;
                    }
                }
            }
            if(t == i) {
                return false;
            }
            i = t;
        }
        return true;
    }
};