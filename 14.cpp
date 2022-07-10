#include <iostream>
#include <vector>
#include <string>


using namespace std;
//最长公共前缀
int main()
{
    vector<string> strs;
    string common;
    int n;
    cin >> n;
    while(n--) {
        string temp;
        cin >> temp;
        strs.push_back(temp);
    }
    if(strs.size() < 2) {
        return 0;
    }
    int arrLength = strs.size(), i = 0;
    int length = strs[0].size();
    while(i < length) {
        char c = strs[0][i];
        int j =1;
        for(; j < arrLength; j++) {
            if(strs[j][i] != c) {
                break;
            }
        }
        if(j != arrLength)
            break;
        i++;
    }
    string result = strs[0].substr(0, i++);
    return 0;
}