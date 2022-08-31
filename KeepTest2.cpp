#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 3;
    cin >> num;
    vector<vector<char>> result;
    for(int i = 0; i < num; i++) {
        vector<char> t(num, '-');
        result.push_back(t);
    }
    for(int i = 0; i < num; i++) {
        result[i][0] = '*';
    }
    for(int i = num - 1; i >= 0; i--) {
        result[i][num - i - 1] = '*';
       
    }
    for(int i = num - 1; i >= num/2; i--) {
        result[i][i] = '*';
    }
    for(auto r : result) {
        for(auto t : r) {
            cout << t;
        }
        cout << endl;
    }
    return 0;
}