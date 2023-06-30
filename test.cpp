#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int S = 5;
    int Y = 4;
    vector<int> index({0, 1, 2, 3, 4});
    vector<int> scores({85, 98, 96, 85, 85});
    // sort(index.begin(), index.end(), [&](int i, int j){
    //     return scores[i] > scores[j];
    // });
    for(int i = 0; i < index.size() - 1; i++) {
        int t = i;
        for(int j = i + 1; j < index.size(); j++) {
            if(scores[index[j]] > scores[index[t]]) {
                 t = j;
            }
        }
        swap(index[i], index[t]);
    }
    for(int i = 0 ; i < index.size(); i++) {
        cout << scores[index[i]] << "  ";
    }
    cout << endl << index[Y] + 1;
    return 0;
}