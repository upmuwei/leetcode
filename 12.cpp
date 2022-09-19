#include <iostream>
#include <map>
#include <string>
//整数转罗马数字
using namespace std;

int main()
{
    int x;
    cin >> x;
    map<int, char> transform;
    transform[1] = 'I';
    transform[5] = 'V';
    transform[10] = 'X';
    transform[50] = 'L';
    transform[100] = 'C';
    transform[500] = 'D';
    transform[1000] = 'M';
    string roman;
    int t = x /1000, divied = 100;
    x = x%1000;
    for(int i = 0; i < t; i++)
        roman.push_back('M');
    while(x) {
        t = x / divied;
        x = x % divied;
        if(t == 9) {
            roman.push_back(transform[divied]);
            roman.push_back(transform[10 * divied]);
            t = 0;
        } else if(t == 4) {
            roman.push_back(transform[divied]);
            roman.push_back(transform[5 * divied]);
            t = 0;
        } else if(t >= 5) {
            roman.push_back(transform[5 * divied]);
            t -= 5;
        }
        for(int i = 0; i< t; i ++) {
            roman.push_back(transform[divied]);
        }
        divied /= 10;
    }
    cout << roman << endl;
    return 0;
}