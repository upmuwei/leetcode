class Solution {
    // 0:向上， 1：向下 ， 2：向左 3：向右
public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        vector<vector<int>> result;
        for(int i = 1; i < plate[0].size() - 1; i++) {
            if(plate[0][i] == '.') {
                if(seek(num, 1, plate, 0, i)) {
                    vector<int> t;
                    t.push_back(0);
                    t.push_back(i);
                    result.push_back(t);
                }
            }
            if(plate[plate.size() - 1][i] == '.') {
                if(seek(num, 0, plate, plate.size() - 1, i)) {
                    vector<int> t;
                    t.push_back(plate.size() - 1);
                    t.push_back(i);
                    result.push_back(t);
                }
            }
        }
        for(int j = 1; j < plate.size() - 1; j++) {
            if(plate[j][0] == '.') {
                if(seek(num, 3, plate, j, 0)) {
                    vector<int> t;
                    t.push_back(j);
                    t.push_back(0);
                    result.push_back(t);
                }
            }
            if(plate[j][plate[0].size() - 1] == '.') {
                if(seek(num, 2, plate, j, plate[0].size() - 1)) {
                    vector<int> t;
                    t.push_back(j);
                    t.push_back(plate[0].size() - 1);
                    result.push_back(t);
                }
            }
        } 
        return result;
    }
        
    bool seek(int num, int direct, vector<string>& plate, int i, int j) {
            bool sign = false;
            if(num < 0) {
                return false;
            }
            if(i < 0 || j < 0 || i >= plate.size() || j >= plate[0].size()) {
                return false;
            }
            if(plate[i][j] == 'O') {
                return true;
            }
            if(direct == 0) {
                if(plate[i][j] == '.') {
                    sign = sign || seek(num-1, 0, plate, i - 1, j);
                }else if(plate[i][j] == 'W') {
                    sign = sign || seek(num-1, 2, plate, i, j - 1);
                }else {
                    sign = sign || seek(num-1, 3, plate, i, j + 1);
                } 
            }
            else if(direct == 1) {
                if(plate[i][j] == '.') {
                    sign = sign || seek(num-1, 1, plate, i + 1, j);
                }else if(plate[i][j] == 'W') {
                    sign = sign || seek(num-1, 3, plate, i, j + 1);
                }else {
                    sign = sign || seek(num-1, 2, plate, i, j - 1);
                } 
            }
            else if(direct == 2) {
                if(plate[i][j] == '.') {
                    sign = sign || seek(num-1, 2, plate, i, j - 1);
                }else if(plate[i][j] == 'W') {
                    sign = sign || seek(num-1, 1, plate, i + 1, j);
                }else {
                    sign = sign || seek(num-1, 0, plate, i - 1, j);
                } 
            }
            else if(direct == 3) {
                if(plate[i][j] == '.') {
                    sign = sign || seek(num-1, 3, plate, i, j + 1);
                }else if(plate[i][j] == 'W') {
                    sign = sign || seek(num-1, 0, plate, i - 1, j);
                }else {
                    sign = sign || seek(num-1, 1, plate, i + 1, j);
                } 
            }
            return sign;
        }
};