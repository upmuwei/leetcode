#include <iostream>
#include <string>
#define MAX 1001
using namespace std;

int main()
{
    char matrix[MAX][MAX] = {{'\0'}};
    int numRows;
    string s;
    cin >> s >> numRows;
    int count = s.size(), p = 0, i = 0, j = 0, sign = 1;
    while(p <= count) {
        matrix[i][j] = s[p];
        if(p % (numRows - 1) == 0) {
            sign = !sign;
        }
        if(sign) {
            i--;
            j++;
        } else {
            i++;
        }
        p++;
    }
    string result;
    for(int i = 0; i <count; i++) {
        for(int j = 0; j < count; j++) {
            if(matrix[i][j] != '\0') {
                result.push_back(matrix[i][j]);
            }
        }
    }
    cout << result << endl;
    return 0;
}

