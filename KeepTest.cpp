#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num = 4321;
    vector<int> figure;
    while(num > 0) {
        figure.push_back(num%10);
        num /= 10;
    }
    for(int i = figure.size() - 1; i > 0; i--) {
        int t = i;
        for(int j = i - 1; j >= 0; j--) {
            if(figure[j] > figure[t]) {
                t = j;
            }
        }
        if(t != i) {
            swap(figure[i], figure[t]);
            break;
        }
    }
    for(int i = figure.size() - 1; i >= 0; i--) {
        num = num * 10 + figure[i];
    }
    cout << num << endl;
    return 0;
}