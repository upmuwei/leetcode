class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i =0; i < board.size(); i++) {
            bool sign1[10] = {false};
            bool sign2[10] = {false};
            for(int j = 0; j < board[i].size(); j++) {
                int t = board[i][j] - '0';
                if(inRange(t)) {
                    if(sign1[t]) {
                        return false;
                    }
                    sign1[t] = true;
                }
                t = board[j][i] - '0';
                if(inRange(t)) {
                    if(sign2[t]) {
                        return false;
                    }
                    sign2[t] = true;
                }
            }
        }
        for(int i = 0; i < board.size(); i += 3) {
        int t = i + 3;
        for(int k = 0; k < 9; k += 3) { // i = 0, k = 6, t=3,g=9
            int g = k + 3;
            bool sign[10] = {false};
            for(int j = i; j < t; j++) {
                for(int q = k; q < g; q++) {    
                    int p = board[j][q] - '0';
                    if(inRange(p)) {
                        if(sign[p]) {
                            return false;
                        }
                        sign[p] = true;
                    }
                }
            }
        }
    }
        return true;
    }
    
    bool inRange(int t) {
        if(t > 0 && t <= 9) {
            return true;
        }
        return false;
    }
};