#include <iostream>
#include <vector>

using namespace std;

int numTimesAllBlue(vector<int>& flips) {
       int count = 0;
       unsigned char y[8] = {1, 3, 7, 15, 31, 63, 127, 255};
       vector<unsigned char> x(flips.size() / 8 + 1, 0);
      
        for(int i = 0; i < flips.size(); i++) {
            int row = (flips[i] - 1) / 8;
            int col = (flips[i] - 1) % 8;
            int j = 0;
            x[row] |= (1 << col);
            row = i / 8;
            for(; j < row; j ++) {
                if(x[j] != y[7]) {
                    break;
                }
            }
            if(j != row) {
                continue;
            }
            else if(x[row] == y[i % 8]) {
                count++;
            }
        }
       return count;
    }

int main() {
    vector<int> flip({1,8,3,4,9,6,7,2,5, 10});
    cout << numTimesAllBlue(flip) << endl;
    return 0;
}