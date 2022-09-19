class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1) {
                    int t;
                    for(t = j + 1; t < mat[i].size(); t++) {
                        if(mat[i][t] == 1) {
                            break;
                        }
                    }
                    if(t == mat[i].size()) {
                        for(t = 0; t < mat.size(); t++) {
                            if((mat[t][j] == 1)&&(t != i)) {
                                break;    
                            }
                        }
                        if(t == mat.size()) {
                            count++;
                        }
                    }
                    break;
                }
            }
        }
        return count;
    }
};